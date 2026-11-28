// P000109 - Linear Search
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++], target = tokens[p++];
const a = tokens.slice(p, p + n);
console.log(a.indexOf(target));
