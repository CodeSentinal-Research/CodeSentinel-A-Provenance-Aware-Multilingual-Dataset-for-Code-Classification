const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000020 - Sum of First N Natural Numbers
console.log(n * (n + 1) / 2);
