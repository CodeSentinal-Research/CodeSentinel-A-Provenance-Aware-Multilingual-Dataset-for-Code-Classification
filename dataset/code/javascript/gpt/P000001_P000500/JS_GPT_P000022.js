const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000022 - Check Prime Number
function isPrime(num) {
    if (num < 2) return false;
    for (let i = 2; i * i <= num; i++) {
        if (num % i === 0) return false;
    }
    return true;
}
console.log(isPrime(n) ? "Prime" : "Not Prime");
