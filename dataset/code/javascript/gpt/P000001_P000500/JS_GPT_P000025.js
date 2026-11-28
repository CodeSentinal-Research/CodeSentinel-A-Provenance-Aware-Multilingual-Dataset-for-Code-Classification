const fs = require("fs");
const s = fs.readFileSync(0, "utf8").trim();
// P000025 - Reverse a Number
const neg = s.startsWith("-");
const digits = neg ? s.slice(1) : s;
const reversed = digits.split("").reverse().join("");
const result = Number(reversed);
console.log(neg ? -result : result);
