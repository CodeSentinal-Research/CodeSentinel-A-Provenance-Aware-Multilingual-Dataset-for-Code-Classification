const fs = require("fs");
const c = fs.readFileSync(0, "utf8").trim()[0];
// P000081 - Check Whether Character is Digit
const isDigit = c >= "0" && c <= "9";
console.log(isDigit ? "Digit" : "Not Digit");
