Here is the JavaScript code for the problem:

function findMin(nums) {
  if (nums.length === 1) {
    return nums[0];
  } else {
    return Math.min(nums[0], findMin(nums.slice(1)));
  }
}

This code defines a function `findMin` that takes in an array of integers as an argument. If the array contains only one element, the function returns that element. Otherwise, it uses the `Math.min` function to find the minimum of the first element and the minimum of the rest of the array. This is done recursively until a single-element array is reached.

Here's how you can use it with an array of integers:

console.log(findMin([3, 2, 1])); // Outputs: 1
console.log(findMin([5, 1, 3, 2, 6])); // Outputs: 1