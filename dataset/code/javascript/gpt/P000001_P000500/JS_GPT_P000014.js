const fs = require("fs");
const [length, breadth] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000014 - Calculate Area of Rectangle
console.log(length * breadth);
