// P000153 - Rearrange Positive and Negative Numbers
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const pos = a.filter(x => x >= 0);
const neg = a.filter(x => x < 0);
const res = [];
let i = 0, j = 0;
while (i < pos.length || j < neg.length) {
    if (i < pos.length) res.push(pos[i++]);
    if (j < neg.length) res.push(neg[j++]);
}
console.log(res.join(" "));
