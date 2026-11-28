const fs = require("fs");
const [a, b, c] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000076 - Find Roots of Quadratic Equation
const D = b * b - 4 * a * c;
if (D > 0) {
    const r1 = (-b + Math.sqrt(D)) / (2 * a);
    const r2 = (-b - Math.sqrt(D)) / (2 * a);
    console.log(r1, r2);
} else if (D === 0) {
    const r = -b / (2 * a);
    console.log(r, r);
} else {
    const real = -b / (2 * a);
    const imag = Math.sqrt(-D) / (2 * a);
    console.log(`${real}+${imag}i ${real}-${imag}i`);
}
