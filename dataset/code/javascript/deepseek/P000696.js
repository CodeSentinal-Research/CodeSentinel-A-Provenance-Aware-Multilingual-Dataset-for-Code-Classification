function lastOccurrence(nums, target) {
  if (nums.length === 0) {
    return -1;
  }
  let start = 0;
  let end = nums.length - 1;
  return binarySearch(nums, target, start, end);
}

function binarySearch(nums, target, start, end) {
  if (start > end) {
    return -1;
  }
  let mid = Math.floor(start + (end - start) / 2);
  if (nums[mid] === target) {
    if (mid === nums.length - 1 || nums[mid + 1] !== target) {
      return mid;
    }
    return binarySearch(nums, target, mid + 1, end);
  }
  if (nums[mid] > target) {
    return binarySearch(nums, target, start, mid - 1);
  }
  return binarySearch(nums, target, mid + 1, end);
}