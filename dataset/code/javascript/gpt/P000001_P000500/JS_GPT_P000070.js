const fs = require("fs");
const [a, b, c] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000070 - Check Whether Triangle is Valid
const valid = a + b > c && b + c > a && a + c > b;
console.log(valid ? "Valid" : "Invalid");
