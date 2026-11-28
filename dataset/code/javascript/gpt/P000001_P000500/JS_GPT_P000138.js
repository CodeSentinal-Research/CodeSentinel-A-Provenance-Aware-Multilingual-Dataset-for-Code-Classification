// P000138 - Merge Two Sorted Arrays
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const m = tokens[p++], n = tokens[p++];
const a = tokens.slice(p, p + m); p += m;
const b = tokens.slice(p, p + n);
const merged = a.concat(b).sort((x, y) => x - y);
console.log(merged.join(" "));
