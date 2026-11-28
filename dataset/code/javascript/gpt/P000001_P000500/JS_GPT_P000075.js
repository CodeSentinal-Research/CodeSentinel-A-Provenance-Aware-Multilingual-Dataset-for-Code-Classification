const fs = require("fs");
const [r, h] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000075 - Calculate Volume of Cylinder
const pi = 3.14159;
console.log(pi * r * r * h);
