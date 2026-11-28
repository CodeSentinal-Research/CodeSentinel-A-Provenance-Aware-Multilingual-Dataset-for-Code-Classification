// Dense linear algebra for small matrices: QR least squares, one-sided Jacobi
// SVD, rank / condition number / pseudo-inverse, and basic products.
// Matrices are arrays of row Float64Arrays.

export function zeros(rows, cols) {
  const out = [];
  for (let i = 0; i < rows; i++) out.push(new Float64Array(cols));
  return out;
}

export function matVec(A, x) {
  const out = new Float64Array(A.length);
  for (let i = 0; i < A.length; i++) {
    let acc = 0;
    const row = A[i];
    for (let j = 0; j < row.length; j++) acc += row[j] * x[j];
    out[i] = acc;
  }
  return out;
}

export function matTVec(A, y) {
  const cols = A.length ? A[0].length : 0;
  const out = new Float64Array(cols);
  for (let i = 0; i < A.length; i++) {
    const row = A[i];
    for (let j = 0; j < cols; j++) out[j] += row[j] * y[i];
  }
  return out;
}

export function transpose(A) {
  const rows = A.length;
  const cols = rows ? A[0].length : 0;
  const out = zeros(cols, rows);
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) out[j][i] = A[i][j];
  }
  return out;
}

export function matMul(A, B) {
  const rows = A.length;
  const inner = B.length;
  const cols = inner ? B[0].length : 0;
  const out = zeros(rows, cols);
  for (let i = 0; i < rows; i++) {
    for (let k = 0; k < inner; k++) {
      const a = A[i][k];
      if (a === 0) continue;
      const rowB = B[k];
      const rowO = out[i];
      for (let j = 0; j < cols; j++) rowO[j] += a * rowB[j];
    }
  }
  return out;
}

// Least squares via Householder QR with column pivoting fallback to normal
// equations for rank-deficient cases; A is m x n (m >= n typical).
export function solveLeastSquares(A, b) {
  const m = A.length;
  const n = m ? A[0].length : 0;
  // Work on copies.
  const R = A.map((row) => Float64Array.from(row));
  const y = Float64Array.from(b);
  for (let k = 0; k < Math.min(m - 1, n); k++) {
    // Householder vector for column k.
    let normX = 0;
    for (let i = k; i < m; i++) normX += R[i][k] * R[i][k];
    normX = Math.sqrt(normX);
    if (normX === 0) continue;
    const alpha = R[k][k] > 0 ? -normX : normX;
    const v = new Float64Array(m - k);
    v[0] = R[k][k] - alpha;
    for (let i = k + 1; i < m; i++) v[i - k] = R[i][k];
    let vNorm2 = 0;
    for (let i = 0; i < v.length; i++) vNorm2 += v[i] * v[i];
    if (vNorm2 === 0) continue;
    for (let j = k; j < n; j++) {
      let dot = 0;
      for (let i = k; i < m; i++) dot += v[i - k] * R[i][j];
      const scale = (2 * dot) / vNorm2;
      for (let i = k; i < m; i++) R[i][j] -= scale * v[i - k];
    }
    let dotB = 0;
    for (let i = k; i < m; i++) dotB += v[i - k] * y[i];
    const scaleB = (2 * dotB) / vNorm2;
    for (let i = k; i < m; i++) y[i] -= scaleB * v[i - k];
  }
  // Back substitution (columns beyond the row count stay at zero for
  // underdetermined systems).
  const x = new Float64Array(n);
  for (let j = n - 1; j >= 0; j--) {
    if (j >= m) continue;
    let acc = y[j];
    for (let k = j + 1; k < n; k++) acc -= R[j][k] * x[k];
    x[j] = Math.abs(R[j][j]) > 1e-300 ? acc / R[j][j] : 0;
  }
  return x;
}

// One-sided Jacobi SVD. Returns { U, s, V } with A = U diag(s) V^T,
// s descending. A is m x n with any shape (transposes internally if m < n).
export function svd(A) {
  const m = A.length;
  const n = m ? A[0].length : 0;
  if (m < n) {
    const { U, s, V } = svd(transpose(A));
    return { U: V, s, V: U };
  }
  // Work matrix W (m x n), V starts as identity (n x n).
  const W = A.map((row) => Float64Array.from(row));
  const V = zeros(n, n);
  for (let i = 0; i < n; i++) V[i][i] = 1;
  const eps = 1e-15;
  for (let sweep = 0; sweep < 60; sweep++) {
    let offDiag = 0;
    for (let p = 0; p < n - 1; p++) {
      for (let q = p + 1; q < n; q++) {
        let alpha = 0;
        let beta = 0;
        let gamma = 0;
        for (let i = 0; i < m; i++) {
          alpha += W[i][p] * W[i][p];
          beta += W[i][q] * W[i][q];
          gamma += W[i][p] * W[i][q];
        }
        offDiag = Math.max(offDiag, Math.abs(gamma) / Math.max(Math.sqrt(alpha * beta), 1e-300));
        if (Math.abs(gamma) < eps * Math.sqrt(alpha * beta) || gamma === 0) continue;
        const zeta = (beta - alpha) / (2 * gamma);
        const t = Math.sign(zeta) / (Math.abs(zeta) + Math.sqrt(1 + zeta * zeta));
        const c = 1 / Math.sqrt(1 + t * t);
        const s = c * t;
        for (let i = 0; i < m; i++) {
          const wp = W[i][p];
          const wq = W[i][q];
          W[i][p] = c * wp - s * wq;
          W[i][q] = s * wp + c * wq;
        }
        for (let i = 0; i < n; i++) {
          const vp = V[i][p];
          const vq = V[i][q];
          V[i][p] = c * vp - s * vq;
          V[i][q] = s * vp + c * vq;
        }
      }
    }
    if (offDiag < 1e-14) break;
  }
  // Singular values are column norms of W; U columns are normalized columns.
  const s = new Float64Array(n);
  const U = zeros(m, n);
  const order = Array.from({ length: n }, (_, i) => i);
  const norms = new Float64Array(n);
  for (let j = 0; j < n; j++) {
    let norm = 0;
    for (let i = 0; i < m; i++) norm += W[i][j] * W[i][j];
    norms[j] = Math.sqrt(norm);
  }
  order.sort((a, b) => norms[b] - norms[a]);
  const Vsorted = zeros(n, n);
  for (let jj = 0; jj < n; jj++) {
    const j = order[jj];
    s[jj] = norms[j];
    if (norms[j] > 1e-300) {
      for (let i = 0; i < m; i++) U[i][jj] = W[i][j] / norms[j];
    }
    for (let i = 0; i < n; i++) Vsorted[i][jj] = V[i][j];
  }
  return { U, s, V: Vsorted };
}

// np.linalg.matrix_rank default tolerance: s_max * max(m, n) * eps
export function matrixRank(A) {
  const m = A.length;
  const n = m ? A[0].length : 0;
  if (!m || !n) return 0;
  const { s } = svd(A);
  const tol = s[0] * Math.max(m, n) * 2.220446049250313e-16;
  let rank = 0;
  for (let i = 0; i < s.length; i++) if (s[i] > tol) rank += 1;
  return rank;
}

// np.linalg.cond (2-norm): s_max / s_min
export function cond2(A) {
  const { s } = svd(A);
  if (!s.length) return Infinity;
  const sMin = s[s.length - 1];
  if (sMin === 0) return Infinity;
  return s[0] / sMin;
}

// np.linalg.pinv with relative rcond.
export function pinv(A, rcond = 1e-12) {
  const m = A.length;
  const n = m ? A[0].length : 0;
  const { U, s, V } = svd(A);
  const cutoff = rcond * (s.length ? s[0] : 0);
  const out = zeros(n, m);
  for (let k = 0; k < s.length; k++) {
    if (s[k] <= cutoff) continue;
    const inv = 1 / s[k];
    for (let i = 0; i < n; i++) {
      const vik = V[i][k] * inv;
      if (vik === 0) continue;
      for (let j = 0; j < m; j++) out[i][j] += vik * U[j][k];
    }
  }
  return out;
}

export function norm2(x) {
  let acc = 0;
  for (let i = 0; i < x.length; i++) acc += x[i] * x[i];
  return Math.sqrt(acc);
}

export function normInf(x) {
  let best = 0;
  for (let i = 0; i < x.length; i++) best = Math.max(best, Math.abs(x[i]));
  return best;
}
