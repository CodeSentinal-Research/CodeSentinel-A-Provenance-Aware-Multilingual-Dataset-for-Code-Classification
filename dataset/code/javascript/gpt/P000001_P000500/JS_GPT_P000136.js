// P000136 - Find All Duplicates
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const seen = new Set(), duplicates = [];
for (const x of a) {
    if (seen.has(x)) duplicates.push(x);
    else seen.add(x);
}
console.log(duplicates.join(" "));
