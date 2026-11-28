// P000117 - Check for Duplicate Elements
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const unique = new Set(a);
console.log(unique.size < n ? "Yes" : "No");
