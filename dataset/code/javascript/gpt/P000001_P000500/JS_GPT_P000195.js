// P000195 - Cyclically Rotate Array by One
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
if (n > 0) {
    const last = a.pop();
    a.unshift(last);
}
console.log(a.join(" "));
