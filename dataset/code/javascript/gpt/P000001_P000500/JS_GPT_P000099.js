const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000099 - Print Floyd Triangle
let num = 1;
for (let i = 1; i <= n; i++) {
    const row = [];
    for (let j = 1; j <= i; j++) row.push(num++);
    console.log(row.join(" "));
}
