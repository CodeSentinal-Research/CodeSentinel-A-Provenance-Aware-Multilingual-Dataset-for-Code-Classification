const fs = require("fs");
const [a, b, c] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000041 - Calculate Average of Three Numbers
console.log((a + b + c) / 3);
