const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++];
let x = 0;
const out = [];
for (let i = 0; i < n; i++) {
    x ^= d[p++];
    out.push(x);
}
console.log(out.join(" "));
