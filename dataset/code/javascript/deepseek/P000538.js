function shortestSubarray(nums, k) {
  let minLength = Infinity;
  let prefixSum = new Array(nums.length + 1).fill(0);
  let prefixSums = [0];
  
  for(let i = 0; i < nums.length; i++) {
    prefixSum[i + 1] = prefixSum[i] + nums[i];
    prefixSums.push(prefixSum[i + 1]);
  }

  for(let i = 0; i < prefixSums.length; i++) {
    if(prefixSums[i] >= k) {
      minLength = Math.min(minLength, i + 1);
    }
  }

  if(minLength === Infinity) {
    return -1;
  }

  for(let i = 0; i < prefixSums.length; i++) {
    if(prefixSums[i] + k >= prefixSums[i + 1]) {
      minLength = Math.min(minLength, i + 1);
    }
  }

  return minLength === Infinity ? -1 : minLength;
}
This solution works by first creating a new array `prefixSum`, which stores the cumulative sum of the `nums` array from index 0 to current index. Then it creates another array `prefixSums`, which stores the `prefixSum` array values in a sorted manner.

The main logic of the solution is to find the minimum length of a non-empty subarray whose sum is at least `k`. This is achieved by looping through both `prefixSums` and `prefixSum`, and checking if the sum of `prefixSum[i]` and `k` is larger or equal to the next element in `prefixSums`. 

The time complexity of this solution is O(nlogn) due to the sorting operation, where n is the length of the input array. The space complexity is O(n) for storing the prefixSum and prefixSums arrays.