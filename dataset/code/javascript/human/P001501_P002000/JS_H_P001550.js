/* ============================================================
   Gradient Lab — a real reverse-mode autodiff engine.

   This is not a mock-up of autograd for the diagrams to animate over. It is the
   engine the rest of the page actually differentiates through: the MLP, the
   Gaussian policy, and all four RL objectives run on it, and test.js checks
   every op against central finite differences.

   Design notes:
   - Tensors are flat Float64Array + a shape. Arbitrary rank, NumPy broadcasting.
   - Every node records its op name and parents, which is what the graph view
     draws. Nothing is bolted on for the visuals.
   - `requiresGrad` propagates from parameters, so detach() genuinely cuts the
     graph the way it does in PyTorch — which the RL losses depend on.
   ============================================================ */
(function (root) {
"use strict";

/* ---------------------------------------------------------------
   0.  shape plumbing
   --------------------------------------------------------------- */
const prod = (a) => a.reduce((x, y) => x * y, 1);
const sameShape = (a, b) => a.length === b.length && a.every((v, i) => v === b[i]);

function strides(shape) {
  const s = new Array(shape.length);
  let acc = 1;
  for (let i = shape.length - 1; i >= 0; i--) { s[i] = acc; acc *= shape[i]; }
  return s;
}

/** NumPy broadcast: right-align, each dim must match or be 1 */
function broadcastShapes(a, b) {
  const n = Math.max(a.length, b.length);
  const out = new Array(n);
  for (let i = 0; i < n; i++) {
    const A = a[a.length - n + i], B = b[b.length - n + i];
    const av = A === undefined ? 1 : A, bv = B === undefined ? 1 : B;
    if (av !== bv && av !== 1 && bv !== 1)
      throw new Error("cannot broadcast [" + a + "] with [" + b + "]");
    out[i] = Math.max(av, bv);
  }
  return out;
}

/** strides for reading `src` as if it were shaped `dst`; 0 on broadcast axes */
function bstrides(src, dst) {
  const st = strides(src);
  const out = new Array(dst.length).fill(0);
  const off = dst.length - src.length;
  for (let i = 0; i < src.length; i++) {
    out[off + i] = (src[i] === 1 && dst[off + i] !== 1) ? 0 : st[i];
  }
  return out;
}

/** Sum `g` (shaped gshape) back down to `shape`.

    THE canonical autodiff bug is forgetting this. A bias of shape [1,H] added to
    activations of shape [B,H] receives B copies of the gradient, and they must be
    summed, not assigned. Running the broadcast index map backwards and
    accumulating does exactly that, for any rank, with no special cases. */
function unbroadcast(g, gshape, shape) {
  if (sameShape(gshape, shape)) return g;
  const out = new Float64Array(prod(shape));
  const bs = bstrides(shape, gshape);
  const nd = gshape.length, n = prod(gshape);
  const idx = new Array(nd).fill(0);
  for (let k = 0; k < n; k++) {
    let off = 0;
    for (let i = 0; i < nd; i++) off += idx[i] * bs[i];
    out[off] += g[k];
    for (let i = nd - 1; i >= 0; i--) { if (++idx[i] < gshape[i]) break; idx[i] = 0; }
  }
  return out;
}

/* ---------------------------------------------------------------
   1.  the node
   --------------------------------------------------------------- */
let UID = 0;

class Tensor {
  constructor(data, shape, opts) {
    opts = opts || {};
    this.shape = shape.slice();
    this.size = prod(shape);
    this.data = data instanceof Float64Array ? data : Float64Array.from(data);
    if (this.data.length !== this.size)
      throw new Error("data length " + this.data.length + " != shape [" + shape + "]");
    this.grad = null;
    this.parents = opts.parents || [];
    this._backward = opts.backward || null;
    this.op = opts.op || "leaf";
    this.label = opts.label || "";
    this.requiresGrad = opts.requiresGrad != null
      ? opts.requiresGrad
      : this.parents.some((p) => p.requiresGrad);
    this.id = ++UID;
  }
  get isScalar() { return this.size === 1; }
  item() {
    if (this.size !== 1) throw new Error("item() on shape [" + this.shape + "]");
    return this.data[0];
  }
  /** a fresh leaf holding the same numbers, cut off from the graph */
  detach() { return new Tensor(this.data.slice(), this.shape, { requiresGrad: false, op: "detach" }); }
  toArray() {
    if (this.shape.length <= 1) return Array.from(this.data);
    const out = [], st = strides(this.shape);
    const build = (d, off) => {
      if (d === this.shape.length - 1) {
        const r = [];
        for (let i = 0; i < this.shape[d]; i++) r.push(this.data[off + i]);
        return r;
      }
      const r = [];
      for (let i = 0; i < this.shape[d]; i++) r.push(build(d + 1, off + i * st[d]));
      return r;
    };
    return build(0, 0);
  }
}

const tensor = (data, shape, label) =>
  new Tensor(data, shape || [data.length], { requiresGrad: false, label: label });
/** a leaf the gradient should reach */
const param = (data, shape, label) =>
  new Tensor(data, shape || [data.length], { requiresGrad: true, label: label, op: "param" });
const scalar = (v, label) => new Tensor([v], [], { requiresGrad: false, label: label });
const zeros = (shape) => new Tensor(new Float64Array(prod(shape)), shape, { requiresGrad: false });

/* ---------------------------------------------------------------
   2.  elementwise machinery
   --------------------------------------------------------------- */
/** binary elementwise with broadcasting; `df` returns [dA, dB] local partials */
function binary(a, b, name, f, df) {
  const shape = broadcastShapes(a.shape, b.shape);
  const n = prod(shape), nd = shape.length;
  const as = bstrides(a.shape, shape), bs = bstrides(b.shape, shape);
  const out = new Float64Array(n);
  const ai = new Int32Array(n), bi = new Int32Array(n);   // kept for backward
  const idx = new Array(nd).fill(0);
  for (let k = 0; k < n; k++) {
    let ao = 0, bo = 0;
    for (let i = 0; i < nd; i++) { ao += idx[i] * as[i]; bo += idx[i] * bs[i]; }
    ai[k] = ao; bi[k] = bo;
    out[k] = f(a.data[ao], b.data[bo]);
    for (let i = nd - 1; i >= 0; i--) { if (++idx[i] < shape[i]) break; idx[i] = 0; }
  }
  const t = new Tensor(out, shape, { parents: [a, b], op: name });
  t._backward = () => {
    const ga = new Float64Array(prod(shape)), gb = new Float64Array(prod(shape));
    for (let k = 0; k < n; k++) {
      const d = df(a.data[ai[k]], b.data[bi[k]], out[k]);
      ga[k] = d[0] * t.grad[k];
      gb[k] = d[1] * t.grad[k];
    }
    if (a.requiresGrad) accum(a, unbroadcast(ga, shape, a.shape));
    if (b.requiresGrad) accum(b, unbroadcast(gb, shape, b.shape));
  };
  return t;
}

/** unary elementwise; `df(x, y)` is dy/dx */
function unary(a, name, f, df) {
  const n = a.size;
  const out = new Float64Array(n);
  for (let k = 0; k < n; k++) out[k] = f(a.data[k]);
  const t = new Tensor(out, a.shape, { parents: [a], op: name });
  t._backward = () => {
    if (!a.requiresGrad) return;
    const g = new Float64Array(n);
    for (let k = 0; k < n; k++) g[k] = df(a.data[k], out[k]) * t.grad[k];
    accum(a, g);
  };
  return t;
}

/** gradient ACCUMULATION, never assignment.

    A node used in two places receives two contributions, and the multivariate
    chain rule says they add. Assigning instead of adding is silent and wrong:
    the answer is simply the last-written branch. */
function accum(node, g) {
  if (!node.grad) node.grad = new Float64Array(node.size);
  for (let i = 0; i < g.length; i++) node.grad[i] += g[i];
}

/* ---------------------------------------------------------------
   3.  the ops
   --------------------------------------------------------------- */
const add = (a, b) => binary(a, b, "add", (x, y) => x + y, () => [1, 1]);
const sub = (a, b) => binary(a, b, "sub", (x, y) => x - y, () => [1, -1]);
const mul = (a, b) => binary(a, b, "mul", (x, y) => x * y, (x, y) => [y, x]);
const div = (a, b) => binary(a, b, "div", (x, y) => x / y, (x, y) => [1 / y, -x / (y * y)]);
/** elementwise minimum — PPO's min() over the two surrogate branches */
const minimum = (a, b) => binary(a, b, "min", (x, y) => Math.min(x, y),
  (x, y) => (x <= y ? [1, 0] : [0, 1]));
const maximum = (a, b) => binary(a, b, "max", (x, y) => Math.max(x, y),
  (x, y) => (x >= y ? [1, 0] : [0, 1]));

const neg = (a) => unary(a, "neg", (x) => -x, () => -1);
const exp = (a) => unary(a, "exp", Math.exp, (x, y) => y);
const log = (a) => unary(a, "log", Math.log, (x) => 1 / x);
const tanh = (a) => unary(a, "tanh", Math.tanh, (x, y) => 1 - y * y);
const relu = (a) => unary(a, "relu", (x) => (x > 0 ? x : 0), (x) => (x > 0 ? 1 : 0));
const sqrtT = (a) => unary(a, "sqrt", Math.sqrt, (x, y) => 0.5 / y);
const square = (a) => unary(a, "square", (x) => x * x, (x) => 2 * x);
const softplus = (a) => unary(a, "softplus",
  (x) => (x > 30 ? x : Math.log1p(Math.exp(x))),
  (x) => 1 / (1 + Math.exp(-x)));
const sigmoid = (a) => unary(a, "sigmoid", (x) => 1 / (1 + Math.exp(-x)), (x, y) => y * (1 - y));

const addScalar = (a, c) => unary(a, "add", (x) => x + c, () => 1);
const mulScalar = (a, c) => unary(a, "mul", (x) => x * c, () => c);
const powScalar = (a, p) => unary(a, "pow", (x) => Math.pow(x, p),
  (x) => p * Math.pow(x, p - 1));

/** clamp. Note the gradient is ZERO outside the band — that is the whole
    mechanism behind PPO's clipped branch, not an implementation detail. */
const clamp = (a, lo, hi) => unary(a, "clamp",
  (x) => Math.min(hi, Math.max(lo, x)),
  (x) => (x > lo && x < hi ? 1 : 0));

/** [m,k] @ [k,n] -> [m,n] */
function matmul(a, b) {
  if (a.shape.length !== 2 || b.shape.length !== 2) throw new Error("matmul wants rank-2");
  const [m, k] = a.shape, [k2, n] = b.shape;
  if (k !== k2) throw new Error("matmul shape mismatch [" + a.shape + "] @ [" + b.shape + "]");
  const out = new Float64Array(m * n);
  for (let i = 0; i < m; i++) {
    for (let p = 0; p < k; p++) {
      const av = a.data[i * k + p];
      if (av === 0) continue;
      for (let j = 0; j < n; j++) out[i * n + j] += av * b.data[p * n + j];
    }
  }
  const t = new Tensor(out, [m, n], { parents: [a, b], op: "matmul" });
  t._backward = () => {
    if (a.requiresGrad) {                        // dA = dC @ B^T
      const ga = new Float64Array(m * k);
      for (let i = 0; i < m; i++)
        for (let j = 0; j < n; j++) {
          const gv = t.grad[i * n + j];
          if (gv === 0) continue;
          for (let p = 0; p < k; p++) ga[i * k + p] += gv * b.data[p * n + j];
        }
      accum(a, ga);
    }
    if (b.requiresGrad) {                        // dB = A^T @ dC
      const gb = new Float64Array(k * n);
      for (let i = 0; i < m; i++)
        for (let p = 0; p < k; p++) {
          const av = a.data[i * k + p];
          if (av === 0) continue;
          for (let j = 0; j < n; j++) gb[p * n + j] += av * t.grad[i * n + j];
        }
      accum(b, gb);
    }
  };
  return t;
}

/** normalise a possibly-negative axis; null means "every axis" */
function axisOf(a, axis) {
  if (axis == null) return null;
  return axis < 0 ? a.shape.length + axis : axis;
}

function reduceShape(shape, ax, keepdim) {
  if (ax == null) return [];
  const s = shape.slice();
  if (keepdim) s[ax] = 1; else s.splice(ax, 1);
  return s;
}

function sum(a, axis, keepdim) {
  if (a.size === 0) throw new Error("cannot reduce a zero-size tensor [" + a.shape + "]");
  const ax = axisOf(a, axis);
  const oshape = reduceShape(a.shape, ax, keepdim);
  const on = prod(oshape);
  const out = new Float64Array(on);
  if (ax == null) {
    let s = 0;
    for (let i = 0; i < a.size; i++) s += a.data[i];
    out[0] = s;
  } else {
    const st = strides(a.shape), n = a.size, nd = a.shape.length;
    const idx = new Array(nd).fill(0);
    const ost = strides(a.shape.slice(0, ax).concat(a.shape.slice(ax + 1)));
    for (let k = 0; k < n; k++) {
      let off = 0, c = 0;
      for (let i = 0; i < nd; i++) if (i !== ax) off += idx[i] * ost[c++];
      out[off] += a.data[k];
      for (let i = nd - 1; i >= 0; i--) { if (++idx[i] < a.shape[i]) break; idx[i] = 0; }
    }
  }
  const t = new Tensor(out, oshape, { parents: [a], op: "sum" });
  t._backward = () => {
    if (!a.requiresGrad) return;
    // every input element contributed exactly once, so the grad broadcasts back
    const kshape = ax == null ? a.shape.map(() => 1) : reduceShape(a.shape, ax, true);
    const bs = bstrides(kshape, a.shape);
    const g = new Float64Array(a.size), nd = a.shape.length;
    const idx = new Array(nd).fill(0);
    for (let k = 0; k < a.size; k++) {
      let off = 0;
      for (let i = 0; i < nd; i++) off += idx[i] * bs[i];
      g[k] = t.grad[off];
      for (let i = nd - 1; i >= 0; i--) { if (++idx[i] < a.shape[i]) break; idx[i] = 0; }
    }
    accum(a, g);
  };
  return t;
}

function mean(a, axis, keepdim) {
  const ax = axisOf(a, axis);
  const count = ax == null ? a.size : a.shape[ax];
  if (!count) throw new Error("cannot average over an empty axis of [" + a.shape + "]");
  return mulScalar(sum(a, axis, keepdim), 1 / count);
}

/** max over an axis, no gradient — used only to stabilise logsumexp */
function amaxData(a, ax) {
  const oshape = reduceShape(a.shape, ax, true);
  const on = prod(oshape);
  const out = new Float64Array(on).fill(-Infinity);
  const bs = bstrides(oshape, a.shape), nd = a.shape.length;
  const idx = new Array(nd).fill(0);
  for (let k = 0; k < a.size; k++) {
    let off = 0;
    for (let i = 0; i < nd; i++) off += idx[i] * bs[i];
    if (a.data[k] > out[off]) out[off] = a.data[k];
    for (let i = nd - 1; i >= 0; i--) { if (++idx[i] < a.shape[i]) break; idx[i] = 0; }
  }
  return new Tensor(out, oshape, { requiresGrad: false });
}

/** log sum exp along an axis, max-shifted.

    The shift is exact, not an approximation: log Σ exp(x) = m + log Σ exp(x−m)
    identically. It only moves where the arithmetic happens, and MPO's dual would
    overflow without it — Q/eta for small eta is enormous. */
function logsumexp(a, axis, keepdim) {
  const ax = axisOf(a, axis == null ? -1 : axis);
  const m = amaxData(a, ax);
  const shifted = sub(a, m);
  const s = sum(exp(shifted), ax, true);
  const r = add(log(s), m);
  return keepdim ? r : reshape(r, reduceShape(a.shape, ax, false));
}

function softmax(a, axis) {
  const ax = axisOf(a, axis == null ? -1 : axis);
  const m = amaxData(a, ax);
  const e = exp(sub(a, m));
  return div(e, sum(e, ax, true));
}

function reshape(a, shape) {
  if (prod(shape) !== a.size)
    throw new Error("reshape [" + a.shape + "] -> [" + shape + "]");
  const t = new Tensor(a.data.slice(), shape, { parents: [a], op: "reshape" });
  t._backward = () => { if (a.requiresGrad) accum(a, t.grad); };
  return t;
}

/** rank-2 transpose */
function transpose(a) {
  if (a.shape.length !== 2) throw new Error("transpose wants rank-2");
  const [m, n] = a.shape;
  const out = new Float64Array(m * n);
  for (let i = 0; i < m; i++) for (let j = 0; j < n; j++) out[j * m + i] = a.data[i * n + j];
  const t = new Tensor(out, [n, m], { parents: [a], op: "transpose" });
  t._backward = () => {
    if (!a.requiresGrad) return;
    const g = new Float64Array(m * n);
    for (let i = 0; i < m; i++) for (let j = 0; j < n; j++) g[i * n + j] = t.grad[j * m + i];
    accum(a, g);
  };
  return t;
}

/* ---------------------------------------------------------------
   4.  the backward pass
   --------------------------------------------------------------- */
/** reverse topological order: a node is visited only after every node that
    consumes it. Get this wrong and adjoints are read before they are finished. */
function topoSort(rootNode) {
  const order = [], seen = new Set(), stack = [[rootNode, false]];
  while (stack.length) {
    const [n, expanded] = stack.pop();
    if (expanded) { order.push(n); continue; }
    if (seen.has(n.id)) continue;
    seen.add(n.id);
    stack.push([n, true]);
    for (const p of n.parents) if (!seen.has(p.id)) stack.push([p, false]);
  }
  return order;                                  // parents before children
}

function backward(rootNode, seed) {
  if (rootNode.size !== 1 && !seed)
    throw new Error("backward() needs a scalar root, or an explicit seed");
  const order = topoSort(rootNode);
  for (const n of order) n.grad = new Float64Array(n.size);
  if (seed) rootNode.grad.set(seed); else rootNode.grad[0] = 1;
  for (let i = order.length - 1; i >= 0; i--) {
    const n = order[i];
    if (n._backward) n._backward();
  }
  return order;
}

function zeroGrad(list) { for (const p of list) p.grad = null; }

/* ---------------------------------------------------------------
   5.  verification: central finite differences
   --------------------------------------------------------------- */
/** Compare analytic grads against (f(x+h) − f(x−h)) / 2h.

    Central differences have O(h^2) truncation error against forward's O(h), and
    with h ~ 1e-5 on float64 the truncation and round-off terms are both around
    1e-10 — which is why the tolerance below can be tight. Relative error is the
    right criterion: an absolute one fails on large gradients and passes
    anything on small ones. */
function gradCheck(lossFn, params, opts) {
  opts = opts || {};
  const h = opts.h || 1e-5;
  const tol = opts.tol || 1e-6;
  // Relative error is the wrong criterion for a gradient that is essentially
  // zero: central differences on a loss of O(1) carry absolute noise around
  // 1e-11, so a true gradient of 1e-8 is judged against numerical dust.
  // `absTol` lets a caller say "below this magnitude, don't ask".
  const absTol = opts.absTol || 0;
  const maxPer = opts.maxPer || 12;
  const out = { worst: 0, checked: 0, fails: [] };

  zeroGrad(params);
  const L = lossFn();
  backward(L);
  const analytic = params.map((p) => (p.grad ? p.grad.slice() : new Float64Array(p.size)));

  for (let pi = 0; pi < params.length; pi++) {
    const p = params[pi];
    const step = Math.max(1, Math.floor(p.size / maxPer));
    for (let i = 0; i < p.size; i += step) {
      const orig = p.data[i];
      p.data[i] = orig + h; const lp = lossFn().item();
      p.data[i] = orig - h; const lm = lossFn().item();
      p.data[i] = orig;
      const num = (lp - lm) / (2 * h);
      const ana = analytic[pi][i];
      const denom = Math.max(1e-8, Math.abs(num) + Math.abs(ana));
      const rel = Math.abs(num - ana) / denom;
      out.checked++;
      const negligible = Math.abs(num - ana) <= absTol;
      if (rel > out.worst && !negligible) out.worst = rel;
      if (rel > tol && !negligible) out.fails.push({ param: p.label || pi, i, num, ana, rel });
    }
  }
  return out;
}

/* ---------------------------------------------------------------
   6.  exports
   --------------------------------------------------------------- */
root.ag = {
  Tensor, tensor, param, scalar, zeros,
  add, sub, mul, div, neg, minimum, maximum,
  exp, log, tanh, relu, sqrt: sqrtT, square, softplus, sigmoid,
  addScalar, mulScalar, powScalar, clamp,
  matmul, sum, mean, logsumexp, softmax, reshape, transpose,
  backward, topoSort, zeroGrad, gradCheck,
  prod, strides, broadcastShapes, bstrides, unbroadcast, sameShape
};

})(typeof window !== "undefined" ? (window.GL = window.GL || {}) : (module.exports = {}));
