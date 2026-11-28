const fs = require("fs");
const [a, b, c] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000071 - Find Type of Triangle
if (a === b && b === c) {
    console.log("Equilateral");
} else if (a === b || b === c || a === c) {
    console.log("Isosceles");
} else {
    console.log("Scalene");
}
