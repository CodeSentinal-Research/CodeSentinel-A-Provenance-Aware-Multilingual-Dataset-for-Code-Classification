const fs = require("fs");
const [scored, total] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000048 - Calculate Percentage
console.log((scored / total) * 100);
