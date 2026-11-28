function findMaxLength(nums) {
    let map = new Map();
    let maxLen = 0, sum = 0;
    map.set(0, -1); // default value for sum = 0, index = -1
    for(let i = 0; i < nums.length; i++){
        sum += nums[i] ? 1 : -1;
        if(map.has(sum)){
            maxLen = Math.max(maxLen, i - map.get(sum));
        } else {
            map.set(sum, i);
        }
    }
    return maxLen;
}
This code works by using a Map data structure to store the running sum and its corresponding index. If the sum is seen before in the map, it means that a subarray with equal sum has been found. The maximum length of this subarray is the difference between the current index and the index in the map. If the sum is not seen before, it is stored in the map with its index.