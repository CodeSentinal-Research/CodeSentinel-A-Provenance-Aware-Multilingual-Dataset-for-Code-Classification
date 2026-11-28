const fs = require("fs");
fs.readFileSync(0, "utf8");
// P000054 - Print Alphabet from A to Z
const letters = [];
for (let i = 65; i <= 90; i++) letters.push(String.fromCharCode(i));
console.log(letters.join(" "));
