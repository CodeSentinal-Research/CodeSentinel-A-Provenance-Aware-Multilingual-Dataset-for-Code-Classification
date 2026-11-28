const fs = require("fs");

const input = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;

if (input.length < 3) {
  process.exit(0);
}

const n = input[p++];
const m = input[p++];
const k = input[p++];

const pref = Array.from({ length: n + 1 }, () => new Float64Array(m + 1));

for (let i = 1; i <= n; i++) {
  for (let j = 1; j <= m; j++) {
    const x = input[p++];
    pref[i][j] = x + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
  }
}

function squareSum(r, c, len) {
  return (
    pref[r + len][c + len] -
    pref[r][c + len] -
    pref[r + len][c] +
    pref[r][c]
  );
}

/*
 * With arbitrary positive and negative entries, feasibility is not monotone
 * in the square size, so binary search on the side length is invalid.
 * Check sizes from largest to smallest and stop at the first feasible size.
 */
const maxLen = Math.min(n, m);

for (let len = maxLen; len >= 1; len--) {
  for (let r = 0; r + len <= n; r++) {
    for (let c = 0; c + len <= m; c++) {
      if (squareSum(r, c, len) <= k) {
        console.log(len);
        process.exit(0);
      }
    }
  }
}

console.log(0);
