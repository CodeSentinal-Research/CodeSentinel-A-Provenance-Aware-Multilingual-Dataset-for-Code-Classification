function factorial(n) {
  if (n < 0 || !Number.isInteger(n)) {
    throw new Error('Input must be a non-negative integer');
  }
  let result = 1;
  for (let i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}