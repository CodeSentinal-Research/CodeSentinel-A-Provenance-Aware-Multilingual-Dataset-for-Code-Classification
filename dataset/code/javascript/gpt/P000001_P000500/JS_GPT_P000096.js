const fs = require("fs");
const s = fs.readFileSync(0, "utf8").trim();
// P000096 - Check Spy Number
const digits = s.split("").map(Number);
const sum = digits.reduce((a, b) => a + b, 0);
const prod = digits.reduce((a, b) => a * b, 1);
console.log(sum === prod ? "Spy" : "Not Spy");
