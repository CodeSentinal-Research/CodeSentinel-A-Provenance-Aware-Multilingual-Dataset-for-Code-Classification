Here is a simple JavaScript code snippet that calculates the sum of all prime numbers less than or equal to N:

function isPrime(num) {
  if (num < 2) {
    return false;
  }
  for (let i = 2; i * i <= num; i++) {
    if (num % i === 0) {
      return false;
    }
  }
  return true;
}

function sumPrimes(N) {
  let sum = 0;
  for (let i = 2; i <= N; i++) {
    if (isPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

In this code, the `isPrime` function checks if a number is prime. It first handles the special cases (less than 2), then checks if the number can be divided by any integer (except 1) up to its square root. If it can, then it's not a prime number.

The `sumPrimes` function iterates through all the numbers up to N and adds up the prime numbers to the sum.