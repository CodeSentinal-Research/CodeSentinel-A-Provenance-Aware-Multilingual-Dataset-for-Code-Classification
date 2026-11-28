const fs = require("fs");
const [a, b] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000009 - Find Maximum of Two Numbers
console.log(Math.max(a, b));
