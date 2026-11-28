// P000183 - Count Distinct Elements in Every Window
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++], k = tokens[p++];
const a = tokens.slice(p, p + n);
const count = new Map();
for (let i = 0; i < k; i++) count.set(a[i], (count.get(a[i]) || 0) + 1);
const ans = [count.size];
for (let i = k; i < n; i++) {
    const rem = a[i - k];
    if (count.get(rem) === 1) count.delete(rem);
    else count.set(rem, count.get(rem) - 1);
    count.set(a[i], (count.get(a[i]) || 0) + 1);
    ans.push(count.size);
}
console.log(ans.join(" "));
