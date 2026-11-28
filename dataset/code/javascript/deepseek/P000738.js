Here is the JavaScript code for the problem:

function countArrangement(N) {
  let count = 0;

  function dfs(n, div) {
    if (n === 0) {
      count++;
      return;
    }
    for (let i = 1; i <= n; i++) {
      if (div === 0 || i % div === 0 || div % i === 0) {
        dfs(n - 1, i);
      }
    }
  }

  dfs(N, 0);
  return count;
}

This code defines a recursive function `dfs` that takes two parameters: `n` (the remaining number of numbers to arrange) and `div` (the current divisor). If `n` is 0, it means we have arranged all the numbers, so we increment the count and return. Otherwise, we try to arrange all numbers up to `n` with the current divisor. If the divisor is 0, we can always divide any number by it, so we divide `i` by `div` in the recursive call; otherwise, we only divide `i` by `div` if `i` divides `div`. After calling `dfs` for all numbers up to `n`, we return the count.

The input to this function is the integer `N`, and the function returns the total number of beautiful arrangements.