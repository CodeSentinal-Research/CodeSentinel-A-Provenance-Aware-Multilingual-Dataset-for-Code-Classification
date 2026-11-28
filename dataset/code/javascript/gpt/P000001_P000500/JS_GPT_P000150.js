// P000150 - Sort a Matrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const rows = tokens[p++], cols = tokens[p++];
const all = tokens.slice(p, p + rows * cols).sort((x, y) => x - y);
for (let i = 0; i < rows; i++) {
    console.log(all.slice(i * cols, (i + 1) * cols).join(" "));
}
