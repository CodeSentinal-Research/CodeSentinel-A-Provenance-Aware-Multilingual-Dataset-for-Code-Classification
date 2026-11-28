const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000036 - Convert Decimal to Binary
console.log(n.toString(2));
