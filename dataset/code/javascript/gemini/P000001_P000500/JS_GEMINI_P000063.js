const fs = require('fs');
// Checks prime status or generates prime numbers using sieve.
function isPrime(n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 === 0 || n % 3 === 0) return false;
    for (let i = 5; i * i <= n; i += 6) if (n % i === 0 || n % (i + 2) === 0) return false;
    return true;
}
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const l = parseInt(input[0], 10), r = parseInt(input[1], 10);
        const primes = [];
        for (let i = l; i <= r; i++) if (isPrime(i)) primes.push(i);
        console.log(primes.join(' '));
    }
}
main();