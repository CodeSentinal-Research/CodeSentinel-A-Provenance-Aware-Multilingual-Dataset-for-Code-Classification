// P000177 - Find K Closest Elements
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++], k = tokens[p++], target = tokens[p++];
const a = tokens.slice(p, p + n);
const sorted = a.slice().sort((x, y) => {
    const d1 = Math.abs(x - target), d2 = Math.abs(y - target);
    return d1 !== d2 ? d1 - d2 : x - y;
});
console.log(sorted.slice(0, k).sort((x, y) => x - y).join(" "));
