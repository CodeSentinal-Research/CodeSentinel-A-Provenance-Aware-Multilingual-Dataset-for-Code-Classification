// P001416 - Longest Harmonious Subsequence
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const primes = new Set();
    for (let i = 0; i < n; i++) {
        let x = parseInt(input[1 + i], 10);
        let d = 2;
        while (d * d <= x) {
            if (x % d === 0) {
                primes.add(d);
                while (x % d === 0) x /= d;
            }
            d++;
        }
        if (x > 1) primes.add(x);
    }
    console.log(primes.size);
}

main();
