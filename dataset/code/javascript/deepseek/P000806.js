function findLength(nums) {
    let map = new Map();
    let sum = 0, maxLen = 0;
    for(let i = 0; i < nums.length; i++) {
        sum += nums[i];
        if(sum == 0) maxLen = i + 1;
        if(map[sum]) maxLen = Math.max(maxLen, i - map[sum]);
        else map[sum] = i;
    }
    return maxLen;
}