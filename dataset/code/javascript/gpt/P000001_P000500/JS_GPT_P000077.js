const fs = require("fs");
const [x1, y1, x2, y2] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000077 - Calculate Distance Between Two Points
const dist = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
console.log(dist);
