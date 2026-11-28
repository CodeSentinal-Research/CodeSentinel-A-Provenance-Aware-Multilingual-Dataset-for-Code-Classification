function canPartitionKSubsets(nums, k) {
  const total = nums.reduce((a, b) => a + b, 0);
  if (total % k !== 0) return false;
  const target = total / k;
  const visited = new Set();
  const backtrack = (start = 0, sum = 0, k) => {
    if (k === 0) return true;
    if (start === nums.length) return false;
    for (let i = start; i < nums.length; i++) {
      if (visited.has(i) || sum + nums[i] > target) continue;
      visited.add(i);
      if (backtrack(i + 1, sum + nums[i], k)) return true;
      visited.delete(i);
   
      if (sum + nums[i] === target) {
        if (backtrack(i + 1, 0, k - 1)) return true;
      }
    }
    return false;
  };
  return backtrack();
}