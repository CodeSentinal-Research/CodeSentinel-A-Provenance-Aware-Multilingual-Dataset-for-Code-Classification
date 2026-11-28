// P000232 - Find Median in Row-wise Sorted Matrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const r = tokens[p++], c = tokens[p++];
const all = tokens.slice(p, p + r * c).sort((x, y) => x - y);
console.log(all[Math.floor(all.length / 2)]);
