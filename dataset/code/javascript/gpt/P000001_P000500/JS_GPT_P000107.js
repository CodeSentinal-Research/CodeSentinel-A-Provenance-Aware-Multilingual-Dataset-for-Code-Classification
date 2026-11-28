// P000107 - Check if Array is Sorted Ascending
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let sorted = true;
for (let i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) { sorted = false; break; }
}
console.log(sorted ? "Sorted" : "Not Sorted");
