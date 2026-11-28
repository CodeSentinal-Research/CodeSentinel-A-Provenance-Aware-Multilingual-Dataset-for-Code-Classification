const fs = require("fs");
const s = fs.readFileSync(0, "utf8").trim();
// P000024 - Sum of Digits
const total = s.split("").reduce((acc, ch) => acc + Number(ch), 0);
console.log(total);
