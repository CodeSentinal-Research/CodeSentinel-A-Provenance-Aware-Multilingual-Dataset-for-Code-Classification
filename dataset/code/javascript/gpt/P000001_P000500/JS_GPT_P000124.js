// P000124 - Product of Array Except Self
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const result = Array(n).fill(1);
let prefix = 1;
for (let i = 0; i < n; i++) {
    result[i] = prefix;
    prefix *= a[i];
}
let suffix = 1;
for (let i = n - 1; i >= 0; i--) {
    result[i] *= suffix;
    suffix *= a[i];
}
console.log(result.join(" "));
