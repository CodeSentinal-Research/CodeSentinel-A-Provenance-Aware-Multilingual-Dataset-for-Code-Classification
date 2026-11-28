const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000095 - Check Neon Number
const sq = String(n * n);
const digitSum = sq.split("").reduce((acc, d) => acc + Number(d), 0);
console.log(digitSum === n ? "Neon" : "Not Neon");
