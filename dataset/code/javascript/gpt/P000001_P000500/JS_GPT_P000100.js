const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000100 - Print Pascal Triangle
let row = [1];
for (let i = 0; i < n; i++) {
    console.log(row.join(" "));
    const next = [1];
    for (let j = 1; j < row.length; j++) next.push(row[j - 1] + row[j]);
    next.push(1);
    row = next;
}
