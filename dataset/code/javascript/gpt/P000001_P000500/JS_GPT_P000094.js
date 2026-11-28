const fs = require("fs");
const s = fs.readFileSync(0, "utf8").trim();
const n = Number(s);
// P000094 - Check Harshad Number
const digitSum = s.split("").reduce((acc, d) => acc + Number(d), 0);
console.log(n % digitSum === 0 ? "Harshad" : "Not Harshad");
