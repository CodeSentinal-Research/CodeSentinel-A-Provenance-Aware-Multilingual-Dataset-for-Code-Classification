const fs = require("fs");
const s = fs.readFileSync(0, "utf8").trim();
// P000059 - Find Product of Digits
const product = s.split("").reduce((acc, d) => acc * Number(d), 1);
console.log(product);
