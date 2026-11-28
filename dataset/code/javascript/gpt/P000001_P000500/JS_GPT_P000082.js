const fs = require("fs");
const c = fs.readFileSync(0, "utf8").trim()[0];
// P000082 - Check Whether Character is Special Symbol
const isAlpha = (c >= "A" && c <= "Z") || (c >= "a" && c <= "z");
const isDigit = c >= "0" && c <= "9";
console.log(!isAlpha && !isDigit ? "Special Symbol" : "Not Special Symbol");
