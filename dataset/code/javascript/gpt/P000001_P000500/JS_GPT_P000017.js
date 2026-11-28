const fs = require("fs");
const F = Number(fs.readFileSync(0, "utf8").trim());
// P000017 - Convert Fahrenheit to Celsius
console.log((F - 32) * 5 / 9);
