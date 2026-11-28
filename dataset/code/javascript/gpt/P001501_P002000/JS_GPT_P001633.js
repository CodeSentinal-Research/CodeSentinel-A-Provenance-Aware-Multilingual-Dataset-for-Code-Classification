const fs = require("fs");

const input = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;

if (input.length < 3) {
  process.exit(0);
}

let n = input[p++];
let m = input[p++];
const k = input[p++];

const a = Array.from({ length: n }, () => {
  const row = input.slice(p, p + m);
  p += m;
  return row;
});

/*
 * Fix a pair of rows and collapse the matrix between them into a 1D array.
 * The largest subarray with sum <= K is found with ordered prefix sums.
 */
if (n > m) {
  [n, m] = [m, n];
  const transposed = Array.from({ length: n }, () => new Array(m));
  for (let i = 0; i < a.length; i++) {
    for (let j = 0; j < a[0].length; j++) {
      transposed[j][i] = a[i][j];
    }
  }
  for (let i = 0; i < n; i++) {
    a[i] = transposed[i];
  }
}

class TreapNode {
  constructor(key, priority) {
    this.key = key;
    this.priority = priority;
    this.left = null;
    this.right = null;
  }
}

let seed = 0x9e3779b9;
function rand() {
  seed ^= seed << 13;
  seed ^= seed >>> 17;
  seed ^= seed << 5;
  return seed >>> 0;
}

function rotateRight(y) {
  const x = y.left;
  y.left = x.right;
  x.right = y;
  return x;
}

function rotateLeft(x) {
  const y = x.right;
  x.right = y.left;
  y.left = x;
  return y;
}

function insert(root, key) {
  if (!root) return new TreapNode(key, rand());

  if (key < root.key) {
    root.left = insert(root.left, key);
    if (root.left.priority < root.priority) root = rotateRight(root);
  } else if (key > root.key) {
    root.right = insert(root.right, key);
    if (root.right.priority < root.priority) root = rotateLeft(root);
  }

  return root;
}

function lowerBound(root, target) {
  let cur = root;
  let ans = null;

  while (cur) {
    if (cur.key >= target) {
      ans = cur.key;
      cur = cur.left;
    } else {
      cur = cur.right;
    }
  }

  return ans;
}

let best = 0;

for (let top = 0; top < n; top++) {
  const col = new Float64Array(m);

  for (let bottom = top; bottom < n; bottom++) {
    for (let c = 0; c < m; c++) {
      col[c] += a[bottom][c];
    }

    let root = null;
    let prefix = 0;
    root = insert(root, 0);

    for (let c = 0; c < m; c++) {
      prefix += col[c];

      // Need an earlier prefix >= prefix - K.
      const candidate = lowerBound(root, prefix - k);

      if (candidate !== null) {
        const width = c + 1;
        const height = bottom - top + 1;
        const area = width * height;
        if (area > best) best = area;
      }

      root = insert(root, prefix);
    }
  }
}

console.log(best);
