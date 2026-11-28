Here is the JavaScript code that would solve the problem. This solution counts the number of integers in the range [0, 10^N) that have all unique digits.

function countNumbersWithUniqueDigits(N) {
  if (N < 0 || N > 8) {
    throw new Error('Invalid input! The input must be between 0 and 8.');
  }

  let count = 0;
  for (let i = 0; i < 10; i++) {
    count += Math.pow(10, N);
  }

  return count;
}
In the above code, we first validate the input. If the input N is not within the range of 0 to 8, we throw an error. Then we initialize a counter variable `count` to 0. In the next loop, we iterate through all numbers from 0 to 9. For each number, we calculate the number of integers in the range [0, 10^N) and add this number to the counter. Finally, we return the counter.