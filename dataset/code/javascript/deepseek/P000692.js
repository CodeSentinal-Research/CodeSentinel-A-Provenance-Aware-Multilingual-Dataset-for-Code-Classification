Here is the JavaScript code for the problem:

function isSorted(nums, index = 0) {
  if (index + 1 === nums.length) {
    return true;
  }
  if (nums[index] > nums[index + 1]) {
    return false;
  }
  return isSorted(nums, index + 1);
}

// Testing the function with some inputs
console.log(isSorted([1, 2, 3, 4])); // Outputs: true
console.log(isSorted([1, 3, 2, 4])); // Outputs: false
In this code, we define a function `isSorted` that takes an array and an index. If the index is equal to the length of the array, we return true, because we have reached the end of the array. If the current element is greater than the next element, we return false, because the array is not sorted. Otherwise, we recursively call `isSorted` on the rest of the array with the index increased by one. 

To test this function, we print the result of calling `isSorted` on two arrays: one sorted and one not sorted.