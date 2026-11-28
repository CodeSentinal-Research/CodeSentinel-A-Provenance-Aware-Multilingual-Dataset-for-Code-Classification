Here is the JavaScript code to solve the problem:

function countSubarrays(nums, K) {
    let count = 0;
    let prefixSum = new Array(nums.length + 1).fill(0);
    for (let i = 0; i < nums.length; i++) {
        prefixSum[i + 1] = prefixSum[i] ^ nums[i];
    }
    for (let start = 0; start < prefixSum.length; start++) {
        for (let end = start; end < prefixSum.length; end++) {
            if (prefixSum[start] === K) {
                count++;
            }
            if (prefixSum[end] === K) {
                count++;
            }
        }
    }
    return count;
}
This code works by first calculating the prefix sum array where each element is the XOR of the first i elements in nums. Then it iterates over the prefix sum array to find contiguous subarrays whose XOR equals K. If it finds a XOR of K, it increments the count. It then moves to the next start point and repeats the process. The time complexity is O(n^2) due to the nested loop.