const fs = require("fs");
const s = fs.readFileSync(0, "utf8").trim();
// P000061 - Count Odd Digits
const count = s.split("").filter(d => Number(d) % 2 !== 0).length;
console.log(count);
