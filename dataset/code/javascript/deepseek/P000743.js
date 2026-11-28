function recursiveBubbleSort(nums) {
  if (!nums || nums.length === 0) {
    return [];
  }

  for (let i = 0; i < nums.length; i++) {
    for (let j = 0; j < nums.length - i - 1; j++) {
      if (nums[j] > nums[j + 1]) {
        let tmp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = tmp;
      }
    }
  }

  return nums;
}

console.log(recursiveBubbleSort([5, 4, 3, 2, 1])); // Output: [1, 2, 3, 4, 5]
This JavaScript function, `recursiveBubbleSort`, uses Bubble Sort algorithm. It first checks if the input array is empty or not. If it is, it returns an empty array. If not, it sorts the array using a nested loop. The outer loop iterates through each element in the array. The inner loop compares each element with the next one. If the current element is greater than the next element, it swaps them. The function finally returns the sorted array.

Please note that recursive Bubble Sort is not usually used in practice, since its efficiency is lower than a simple loop-based sorting algorithm. It is mainly used for learning purposes or when the requirements are very specific, such as when implementing certain sorting algorithms or when the problem size is small enough to fit in memory.