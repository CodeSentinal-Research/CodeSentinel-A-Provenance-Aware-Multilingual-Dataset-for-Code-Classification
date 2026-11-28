function minPasses(nums) {
  let passes = 0;
  let left = 0;
  let right = nums.length - 1;

  while (left < right) {
    while (left < right && nums[left] <= nums[left + 1]) {
      left++;
    }

    while (left < right && nums[right] >= nums[right - 1]) {
      right--;
    }

    if (left >= right) {
      break;
    }

    passes++;

    let minValue = Math.min(nums[left], nums[right]);
    nums[left] = minValue;
    nums[right] = minValue;
  }

  return passes;
}
This JavaScript function works by maintaining a strictly increasing sequence by swapping elements at the beginning and end of the array. It works by moving towards the center, comparing adjacent elements and swapping them if necessary. It does this until the array is sorted in increasing order.