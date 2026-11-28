Here is a simple JavaScript code to reverse an array using recursion.

function reverseArray(nums, index = nums.length - 1) {
  if (index < 0) {
    return nums;
  }

  const reversedNums = reverseArray(nums, index - 1);
  return [...reversedNums, nums[index]];
}

// Usage
const nums = [1, 2, 3, 4, 5];
console.log(reverseArray(nums)); // [5, 4, 3, 2, 1]

In the above code, the `reverseArray` function takes an array and an index as parameters. It recursively calls itself with the index decremented until it reaches 0 (base case), then it returns the array. For each recursive call, it adds the element at the current index to the end of the reversed array. This way, the array is reversed.