const fs = require("fs");
const [P, R, T] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000012 - Calculate Simple Interest
const si = (P * R * T) / 100;
console.log(si);
