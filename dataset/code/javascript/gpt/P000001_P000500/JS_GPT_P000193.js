// P000193 - Find Union of Two Unsorted Arrays
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const m = tokens[p++], n = tokens[p++];
const a = tokens.slice(p, p + m); p += m;
const b = tokens.slice(p, p + n);
const unionSet = new Set();
for (let i = 0; i < m; i++) unionSet.add(a[i]);
for (let j = 0; j < n; j++) unionSet.add(b[j]);
console.log(Array.from(unionSet).join(" "));
