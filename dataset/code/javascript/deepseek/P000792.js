Here is a JavaScript solution for the given problem:

function countSubarrays(nums, goal) {
  let count = 0;
  let left = 0;
  let right = 0;
  let sum = 0;

  while (right < nums.length) {
    sum += nums[right];

    while (sum > goal) {
      sum -= nums[left];
      left++;
    }

    if (sum === goal) {
      count += left + 1;
    }

    right++;
  }

  return count;
}

This function iterates over the binary array, and for each element, it calculates the sum of the elements from the current position to the end. If the sum exceeds the goal, it reduces the sum by subtracting the leftmost element, and moves the left pointer one step to the right. If the sum equals the goal, it increments the count and moves both pointers to the right.

Note: The solution assumes that the input is valid, i.e., the `nums` array contains only elements 0 and 1, and the `goal` is a non-negative integer.