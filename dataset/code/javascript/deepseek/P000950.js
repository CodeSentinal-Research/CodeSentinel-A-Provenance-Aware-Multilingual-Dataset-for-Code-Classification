Sure, here's the JavaScript code that solves the problem:

function sieveOfEratosthenes(n) {
    let primes = new Array(n + 1).fill(true);
    primes[0] = primes[1] = false;
    for (let i = 2; i <= Math.sqrt(n); i++) {
        if (primes[i]) {
            for (let j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
    return primes;
}

function totientFunction(n) {
    let sieve = sieveOfEratosthenes(n);
    let totient = new Array(n + 1).fill(0);
    for (let i = 2; i <= n; i++) {
        if (sieve[i]) {
            for (let j = i; j <= n; j += i) {
                totient[j]++;
            }
        }
    }
    return totient;
}

console.log(totientFunction(10));
This code first finds all prime numbers up to N using the sieve of Eratosthenes method. Then it computes the totient function φ(i) for each prime number i up to N, by incrementing the count of each multiple i of the prime number. The function totientFunction returns an array containing φ(1), φ(2), ..., φ(N).

Note: This solution uses the Sieve of Eratosthenes to generate all prime numbers up to N, which is efficient for large N. The time complexity is O(n log log n) for the Sieve of Eratosthenes, and then O(n) for the totient function, resulting in a total time complexity of O(n log log n).