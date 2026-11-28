const fs = require("fs");
const c = fs.readFileSync(0, "utf8").trim()[0];
// P000080 - Check Whether Character is Alphabet
const isAlpha = (c >= "A" && c <= "Z") || (c >= "a" && c <= "z");
console.log(isAlpha ? "Alphabet" : "Not Alphabet");
