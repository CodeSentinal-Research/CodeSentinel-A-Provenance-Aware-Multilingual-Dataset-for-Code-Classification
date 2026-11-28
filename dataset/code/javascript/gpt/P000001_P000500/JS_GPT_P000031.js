const fs = require("fs");
const s = fs.readFileSync(0, "utf8").trim();
const n = Number(s);
// P000031 - Check Armstrong Number
const len = s.length;
const sum = s.split("").reduce((acc, d) => acc + Math.pow(Number(d), len), 0);
console.log(sum === n ? "Armstrong" : "Not Armstrong");
