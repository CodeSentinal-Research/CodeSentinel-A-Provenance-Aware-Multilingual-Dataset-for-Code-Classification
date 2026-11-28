const fs = require("fs");
fs.readFileSync(0, "utf8");
// P000055 - Print Alphabet from Z to A
const letters = [];
for (let i = 90; i >= 65; i--) letters.push(String.fromCharCode(i));
console.log(letters.join(" "));
