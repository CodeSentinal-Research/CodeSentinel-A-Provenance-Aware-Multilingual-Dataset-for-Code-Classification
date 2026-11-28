function firstOccurrence(nums, target, start = 0) {
  if (start === nums.length) {
    return -1;
  }

  if (nums[start] === target) {
    return start;
  }

  return firstOccurrence(nums, target, start + 1);
}

console.log(firstOccurrence([2, 3, 4, 4, 5, 6, 7], 4)); // Output: 2