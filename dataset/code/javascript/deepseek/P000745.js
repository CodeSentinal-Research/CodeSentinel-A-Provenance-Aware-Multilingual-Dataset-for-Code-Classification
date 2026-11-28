function insertionSort(nums) {
  if (nums.length <= 1) {
    return nums;
  }

  let lastElement = nums.pop();
  let sortedArray = insertionSort(nums);

  nums.push(lastElement);
  let i = nums.length - 1;

  while (i > 0 && nums[i - 1] > lastElement) {
    nums[i] = nums[i - 1];
    i--;
  }

  nums[i] = lastElement;

  return nums;
}

let nums = [12, 11, 13, 5, 6];
console.log(insertionSort(nums)); // Outputs: [5, 6, 11, 12, 13]