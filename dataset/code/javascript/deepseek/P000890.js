function countPrimes(n) {
    // Initialize a boolean array "prime" of size n+1 and initialize all elements as true
    let prime = new Array(n+1).fill(true);
    prime[0] = prime[1] = false;

    for (let i = 2; i*i <= n; i++) {
        if (prime[i] === true) {
            // If prime[i] is not changed, then it is a prime
            for (let j = i*i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    // Count the number of prime numbers
    let count = 0;
    for (let i = 2; i < n; i++) {
        if (prime[i] === true) {
            count++;
        }
    }

    return count;
}