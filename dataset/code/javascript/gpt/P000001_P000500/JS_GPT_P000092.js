const fs = require("fs");
const [a, d, n] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000092 - Find Sum of AP Series
console.log((n / 2) * (2 * a + (n - 1) * d));
