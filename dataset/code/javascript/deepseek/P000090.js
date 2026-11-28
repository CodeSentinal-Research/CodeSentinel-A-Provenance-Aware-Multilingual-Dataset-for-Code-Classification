Here is a JavaScript function that calculates the binomial coefficient nCr. This function uses a dynamic programming approach to calculate the binomial coefficient.

function nCr(n, r) {
  // If r is greater than n or r is less than 0 or n is less than 0 or n+r is less than 0, return 0
  if (r > n || r < 0 || n < 0 || n + r < 0) {
    return 0;
  }

  // Initialize a 2D array to store intermediate results
  let arr = Array.from(Array(n + 1), () => Array(r + 1).fill(0));

  // Calculate the binomial coefficient for 0r, 0
  arr[0][0] = 1;

  // Calculate the binomial coefficient for each n from 1 to n
  for (let i = 1; i <= n; i++) {
    arr[i][0] = 1;
    for (let j = 1; j <= r; j++) {
      arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
    }
  }

  // Return the binomial coefficient nCr
  return arr[n][r];
}

// Testing the function
console.log(nCr(5, 2)); // Output: 10

In this code, the function `nCr(n, r)` first checks if the input values for `n` and `r` are valid. If not, it returns 0. Then, it initializes a 2D array `arr` with size `n + 1` by `r + 1`. The element `arr[0][0]` is set to 1, because the binomial coefficient for 0r, 0 is 1.

The function then calculates the binomial coefficient for each `n` from 1 to `n`. For each `i` from 1 to `n`, the function calculates the binomial coefficient for each `j` from 1 to `r`. The binomial coefficient for `arr[i][j]` is calculated as the sum of `arr[i - 1][j - 1]` and `arr[i - 1][j]`.

Finally, the function returns the binomial coefficient `nCr` for `n` and `r`.

The `console.log(nCr(5, 2));` line is a test that calls the `nCr` function with arguments 5 and 2, and outputs the result.