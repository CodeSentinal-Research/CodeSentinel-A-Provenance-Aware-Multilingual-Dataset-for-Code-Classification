const fs = require("fs");
const [length, breadth, height] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000073 - Calculate Volume of Cuboid
console.log(length * breadth * height);
