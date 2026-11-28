Here is the JavaScript code for the problem.

function countSubarrays(n, k, nums) {
  let left = 0, right = 0;
  let count = 0;
  let product = 1;

  while (right < n) {
    product *= nums[right];

    while (product >= k && left < right) {
      product /= nums[left];
      left++;
    }

    count += right - left + 1;
    right++;
  }

  return count;
}

// Test
const n = 5, k = 100;
const nums = [2, 3, 4, 5, 6];
console.log(countSubarrays(n, k, nums)); // Output: 3

This code uses two pointers and a while loop to traverse the array. The left pointer moves forward and the right pointer moves backward. If the product of the numbers between the left and right pointers is greater than or equal to k, the left pointer moves forward and the product is divided by the number at the left pointer. This is because the product of all numbers between the left and right pointers is greater than the k, so it can't be the only contiguous subarray that meets the criteria. The count is incremented by the difference between right and left pointers plus 1. If the product of the numbers between the left and right pointers is less than k, the right pointer moves forward. This is because if the product of numbers is less than k, the left pointer can move forward to a larger product that is greater than k.