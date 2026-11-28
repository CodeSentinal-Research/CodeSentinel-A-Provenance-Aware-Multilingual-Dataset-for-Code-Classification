const fs = require("fs");
const [length, breadth] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000015 - Calculate Perimeter of Rectangle
console.log(2 * (length + breadth));
