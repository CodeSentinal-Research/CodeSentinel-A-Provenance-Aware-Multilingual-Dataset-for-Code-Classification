function isPalindrome(nums) {
  // Base case: if the array is empty, it's a palindrome
  if (nums.length === 0) {
    return true;
  }

  // Base case: if the first and last elements are not equal, it's not a palindrome
  if (nums[0] !== nums[nums.length - 1]) {
    return false;
  }

  // Recursive call: check the rest of the array
  return isPalindrome(nums.slice(1, nums.length - 1));
}

// Example usage:
console.log(isPalindrome([1, 2, 3, 2, 1])); // Output: true
console.log(isPalindrome([1, 2, 3, 4, 5])); // Output: false