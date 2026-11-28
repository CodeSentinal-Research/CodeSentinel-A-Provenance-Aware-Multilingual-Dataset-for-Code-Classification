// P000230 - Common Elements in All Rows of Matrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const r = tokens[p++], c = tokens[p++];
const rows = Array.from({length: r}, () => tokens.slice(p, p += c));
let common = new Set(rows[0]);
for (let i = 1; i < r; i++) {
    const s = new Set(rows[i]);
    common = new Set([...common].filter(x => s.has(x)));
}
console.log(Array.from(common).sort((x, y) => x - y).join(" "));
