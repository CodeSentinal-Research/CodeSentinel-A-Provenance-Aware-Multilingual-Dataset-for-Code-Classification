const fs = require("fs");
const C = Number(fs.readFileSync(0, "utf8").trim());
// P000016 - Convert Celsius to Fahrenheit
console.log((C * 9 / 5) + 32);
