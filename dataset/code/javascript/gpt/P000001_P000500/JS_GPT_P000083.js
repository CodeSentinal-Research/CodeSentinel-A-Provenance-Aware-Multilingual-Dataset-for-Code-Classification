const fs = require("fs");
const [a, b, c] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000083 - Find Largest Among Three Numbers Using Nested If
let largest;
if (a >= b) {
    if (a >= c) { largest = a; } else { largest = c; }
} else {
    if (b >= c) { largest = b; } else { largest = c; }
}
console.log(largest);
