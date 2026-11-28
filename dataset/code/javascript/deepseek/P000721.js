function allIncreasingSubsequences(nums) {
  if (!nums || nums.length === 0) return [];

  const res = [];
  const path = [];

  nums.sort((a, b) => a - b);

  function backtrack(start) {
    if (path.length >= 2) {
      res.push(Array.from(path));
    }

    for (let i = start; i < nums.length; i++) {
      if (path.length >= 2 && nums[i] < path[path.length - 1]) {
        continue;
      }

      if (path.length === 0 || nums[i] > path[path.length - 1]) {
        path.push(nums[i]);
        backtrack(i + 1);
        path.pop();
      }
    }
  }

  backtrack(0);

  return res;
}

console.log(allIncreasingSubsequences([1, 3, 2]));