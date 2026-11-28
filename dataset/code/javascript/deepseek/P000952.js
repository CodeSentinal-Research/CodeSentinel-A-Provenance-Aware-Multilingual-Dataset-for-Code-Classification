To solve this problem, we can use the Euler's totient function, which is a mathematical function that counts the positive integers up to a given integer n which are relatively prime to n. In other words, it counts the positive integers that share no common factors with the given integer.

The Euler's totient function can be represented as:

φ(n) = n * φ(p1) * φ(p2) * ... * φ(pk)

where n is a number and p1, p2, ..., pk are prime factors of n.

Here is the JavaScript code:

function countCoprimeNumbers(N, L, R) {
  if (N < 1 || N > 1e12 || L < 1 || L > 1e12 || R < 1 || R > 1e12) {
    throw new Error('Invalid input.');
  }

  // Create a list of boolean values to represent the numbers
  // initialized to true.
  const isCoprime = new Array(R + 1).fill(true).map(() => true);

  for (let p = 2; p * p <= R; p++) {
    if (isCoprime[p]) {
      // p is prime
      for (let i = p * p; i <= R; i += p) {
        // i is a multiple of p, mark all multiples of p as not coprime
        isCoprime[i] = false;
      }
    }
  }

  let count = 0;

  for (let i = L; i <= R; i++) {
    if (isCoprime[i]) {
      count++;
    }
  }

  return count;
}

This code first checks if the input numbers N, L, and R are valid. Then it creates a list of boolean values representing the numbers from L to R. For each number i from L to R, if it's true (i.e., it's a prime number) it sets all multiples of i to false (since they're not coprime). Finally, it counts the number of true values in the list.

Note: This code uses the Sieve of Eratosthenes algorithm, which is a very efficient way to find all primes up to a given limit. It's a good strategy to find all primes up to a limit.