const fs = require("fs");
const r = Number(fs.readFileSync(0, "utf8").trim());
// P000074 - Calculate Volume of Sphere
const pi = 3.14159;
console.log((4 / 3) * pi * r * r * r);
