const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000098 - Find Sum of Prime Numbers up to N
const sieve = new Array(n + 1).fill(true);
sieve[0] = sieve[1] = false;
for (let i = 2; i * i <= n; i++) {
    if (sieve[i]) {
        for (let j = i * i; j <= n; j += i) sieve[j] = false;
    }
}
let sum = 0;
for (let i = 2; i <= n; i++) { if (sieve[i]) sum += i; }
console.log(sum);
