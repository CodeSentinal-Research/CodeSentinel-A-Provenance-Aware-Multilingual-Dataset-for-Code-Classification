// P000235 - Print Matrix in Zigzag Order
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const r = tokens[p++], c = tokens[p++];
const a = Array.from({length: r}, () => tokens.slice(p, p += c));
const out = [];
for (let i = 0; i < r; i++) {
    if (i % 2 === 0) out.push(...a[i]);
    else out.push(...a[i].slice().reverse());
}
console.log(out.join(" "));
