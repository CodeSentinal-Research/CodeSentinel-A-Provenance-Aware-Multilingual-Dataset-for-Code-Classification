Here is the JavaScript code to solve the linear congruence solver:

function solveCongruence(A, B, M) {
  // check if the numbers are valid
  if (A < 1 || B < 1 || M < 1 || A > Math.pow(10, 18) || B > Math.pow(10, 18) || M > Math.pow(10, 18)) {
    return -1;
  }

  // check if M is a prime number
  if (!isPrime(M)) {
    return -1;
  }

  // use the extended Euclidean algorithm to find the greatest common divisor
  let gcd = gcdExtended(A, M, &x);

  // check if the congruence is true
  if (gcd !== 1) {
    return -1;
  }

  // find the smallest non-negative solution
  let solution = (B - A * x % M + M) % M;

  return solution !== 0 ? solution : -1;
}

// helper function to check if a number is prime
function isPrime(n) {
  if (n <= 1) {
    return false;
  }
  if (n <= 3) {
    return true;
  }
  if (n % 2 === 0 || n % 3 === 0) {
    return false;
  }
  for (let i = 5; i * i <= n; i += 6) {
    if (n % i === 0 || n % (i + 2) === 0) {
      return false;
    }
  }
  return true;
}

// helper function to use the extended Euclidean algorithm
function gcdExtended(a, b, x, y, p) {
  if (a === 0) {
    x = 0;
    y = 1;
    return b;
  }
  let gcd = gcdExtended(b % a, a, &y, &x, p);
  return gcd;
}

This code first checks if the given numbers are valid. Then it uses the extended Euclidean algorithm to find the greatest common divisor of A and M, and checks if the equation A * X ≡ B (mod M) is satisfied. If the greatest common divisor is not 1, it means that the equation is not satisfied. Finally, it finds the smallest non-negative solution, and returns it. If the solution is 0, it means that no solution exists and returns -1.