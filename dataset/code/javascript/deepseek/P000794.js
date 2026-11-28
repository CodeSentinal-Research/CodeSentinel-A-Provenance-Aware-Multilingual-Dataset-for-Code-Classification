function maxSubArrayLen(nums, k) {
    let map = new Map();
    let sum = 0;
    let maxLen = 0;
    
    for (let i = 0; i < nums.length; i++) {
        sum += nums[i];
        if (sum === k) {
            maxLen = i + 1;
        }
        if (map.has(sum - k)) {
            maxLen = Math.max(maxLen, i - map.get(sum - k));
        }
        if (!map.has(sum)) {
            map.set(sum, i);
        }
    }
    
    return maxLen;
}