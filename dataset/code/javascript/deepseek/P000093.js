Here is the JavaScript code for your problem:

function sumOfGP(a, r, n) {
  if (n < 1 || n > 20) {
    throw new Error('n must be between 1 and 20');
  }

  let sum = 0;
  for (let i = 0; i < n; i++) {
    sum += a;
    a *= r;
  }

  return sum;
}

In this code, a and r are the first and common ratio of the geometric progression, respectively. The loop calculates the sum of the geometric progression, starting from the first term a, and multiplying each term by the common ratio r.

Please note that in the problem statement, the constraint 1 ≤ n ≤ 20 is not clear, and the input is not clear. If n is the number of terms, then the sum should be calculated up to n terms.

Also, the function doesn't have any error handling. In a real world situation, you should always check if the input parameters are valid, and throw appropriate errors if they are not.

This function should work for any input a, r, and n. For example, if you call `sumOfGP(2, 3, 5)`, it will calculate the sum of the geometric progression `2, 6, 18, 54, 162`.