const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000023 - Print Fibonacci Series
const fib = [];
let a = 0, b = 1;
for (let i = 0; i < n; i++) {
    fib.push(a);
    [a, b] = [b, a + b];
}
console.log(fib.join(" "));
