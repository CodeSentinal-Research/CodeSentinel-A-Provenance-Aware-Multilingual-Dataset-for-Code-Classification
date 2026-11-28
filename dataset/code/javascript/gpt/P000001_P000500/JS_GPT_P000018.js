const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000018 - Check Leap Year
const leap = n % 400 === 0 || (n % 4 === 0 && n % 100 !== 0);
console.log(leap ? "Leap Year" : "Not a Leap Year");
