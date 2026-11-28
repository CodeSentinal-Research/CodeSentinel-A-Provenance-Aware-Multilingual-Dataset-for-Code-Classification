const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000088 - Check Whether Number is Perfect Square
const sq = Math.round(Math.sqrt(n));
console.log(sq * sq === n ? "Perfect Square" : "Not Perfect Square");
