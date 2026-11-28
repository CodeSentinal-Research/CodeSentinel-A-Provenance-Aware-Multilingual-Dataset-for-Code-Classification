const fs = require("fs");
const [a, b] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000010 - Find Minimum of Two Numbers
console.log(Math.min(a, b));
