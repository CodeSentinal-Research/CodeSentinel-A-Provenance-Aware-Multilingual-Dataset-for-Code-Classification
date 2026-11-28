const fs = require("fs");
const s = fs.readFileSync(0, "utf8").trim();
const n = Number(s);
// P000062 - Check Strong Number
function factorial(x) {
    let f = 1;
    for (let i = 2; i <= x; i++) f *= i;
    return f;
}
const sum = s.split("").reduce((acc, d) => acc + factorial(Number(d)), 0);
console.log(sum === n ? "Strong" : "Not Strong");
