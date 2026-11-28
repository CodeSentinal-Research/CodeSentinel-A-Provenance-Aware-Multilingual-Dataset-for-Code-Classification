const fs = require("fs");
const [a, r, n] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000093 - Find Sum of GP Series
if (r === 1) {
    console.log(a * n);
} else {
    console.log(a * (Math.pow(r, n) - 1) / (r - 1));
}
