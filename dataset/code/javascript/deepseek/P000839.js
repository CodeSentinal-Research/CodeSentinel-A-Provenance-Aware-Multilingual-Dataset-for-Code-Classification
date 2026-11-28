Here is the JavaScript code to solve the problem:

function smallestDivisor(nums, threshold) {
  function sumCeiling(num, divisor) {
    return Math.ceil(num / divisor);
  }

  let left = 1;
  let right = 1000000;

  while (left < right) {
    let mid = Math.floor((left + right) / 2);
    if (nums.reduce((sum, num) => sum + sumCeiling(num, mid), 0) > threshold) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return left;
}

This function uses binary search to find the smallest divisor. It starts by setting the left and right bounds of the search to 1 and 1000000, respectively. Then it enters a loop where it computes the midpoint and checks whether the sum of the ceiling of each number divided by the divisor is greater than the threshold. If it is, it sets the left bound to mid + 1. Otherwise, it sets the right bound to mid. The loop continues until the left bound is equal to the right bound, at which point it returns the left bound as the smallest divisor.