const fs = require("fs");
const [L, R] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000063 - Print Prime Numbers in Range
function isPrime(num) {
    if (num < 2) return false;
    for (let i = 2; i * i <= num; i++) {
        if (num % i === 0) return false;
    }
    return true;
}
const primes = [];
for (let i = L; i <= R; i++) { if (isPrime(i)) primes.push(i); }
console.log(primes.join(" "));
