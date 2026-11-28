const fs = require("fs");
const [a, b, c] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000011 - Find Maximum of Three Numbers
console.log(Math.max(a, b, c));
