Here is the JavaScript code for the problem:

function permutation(n, r) {
  if (r < 0 || r > n) {
    return 'Invalid input';
  }
  let result = 1;
  for (let i = 1; i <= r; i++) {
    result *= n - i + 1;
    result /= i;
  }
  return result;
}

This function takes two arguments, n and r, and returns the number of permutations nPr for the given n and r. If r is less than 0 or greater than n, it returns an error message. Otherwise, it calculates the result as nPr using a loop and factorial calculation. The factorial of a number is the product of all positive integers less than or equal to that number.