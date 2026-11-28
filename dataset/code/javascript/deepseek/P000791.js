function longestSubarrayWithSumK(nums, k) {
  let map = new Map();
  let sum = 0;
  let maxLength = 0;
  
  for (let i = 0; i < nums.length; i++) {
    sum += nums[i];
    
    if (sum === k) {
      maxLength = Math.max(maxLength, i + 1);
      map.set(sum, i);
    }
    
    if (map.has(sum - k) && maxLength < i - map.get(sum - k)) {
      maxLength = i - map.get(sum - k);
    }
  }
  
  return maxLength;
}