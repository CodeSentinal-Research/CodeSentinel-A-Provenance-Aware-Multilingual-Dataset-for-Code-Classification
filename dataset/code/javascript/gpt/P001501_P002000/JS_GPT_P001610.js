const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++];
const a = d.slice(p, p + n);
const out = new Array(n).fill(1);
let left = 1;
for (let i = 0; i < n; i++) {
    out[i] = left;
    left *= a[i];
}
let right = 1;
for (let i = n - 1; i >= 0; i--) {
    out[i] *= right;
    right *= a[i];
}
console.log(out.join(" "));
