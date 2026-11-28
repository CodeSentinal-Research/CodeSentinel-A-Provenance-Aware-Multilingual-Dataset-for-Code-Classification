const fs = require("fs");
const [n, r] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000091 - Calculate nPr
function factorial(x) {
    let f = 1;
    for (let i = 2; i <= x; i++) f *= i;
    return f;
}
console.log(factorial(n) / factorial(n - r));
