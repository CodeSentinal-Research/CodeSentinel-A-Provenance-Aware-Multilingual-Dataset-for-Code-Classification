const fs = require("fs");
const s = fs.readFileSync(0, "utf8").trim();
// P000037 - Convert Binary to Decimal
console.log(parseInt(s, 2));
