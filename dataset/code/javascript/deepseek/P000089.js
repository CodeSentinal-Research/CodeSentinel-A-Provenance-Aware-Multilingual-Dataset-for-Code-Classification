Here is the JavaScript code for finding the integer square root of a non-negative integer:

function squareRoot(n) {
  // Input validation
  if (n < 0 || n > 10^9) {
    throw new Error('Invalid input! Input must be a non-negative integer less than or equal to 10^9');
  }

  // Binary search for the square root
  let start = 0;
  let end = Math.min(n, 463); // 463 is the largest integer less than sqrt(10^9)
  while (start < end) {
    let mid = Math.floor((start + end) / 2);
    if (mid * mid <= n) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }
  return end - 1;
}

In this code, we use a binary search algorithm to find the square root. The binary search range is from 0 to the smallest integer less than `n` and `463`, as this is the largest integer less than the square root of `10^9`. In each iteration of the loop, we calculate the midpoint and decide which half of the range to search in. If the square of the midpoint is less than or equal to `n`, we increase the start pointer to search the right half of the range; otherwise, we decrease the end pointer to search the left half of the range. The loop continues until the start pointer is equal to the end pointer, which means that we found the square root of `n`.