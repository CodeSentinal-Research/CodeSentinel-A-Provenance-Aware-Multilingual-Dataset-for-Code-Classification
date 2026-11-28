// P000214 - Find All Numbers Disappeared in Array
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const seen = new Set(a);
const missing = [];
for (let i = 1; i <= n; i++) if (!seen.has(i)) missing.push(i);
console.log(missing.join(" "));
