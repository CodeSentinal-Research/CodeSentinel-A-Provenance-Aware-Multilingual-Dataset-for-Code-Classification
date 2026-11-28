Here is the JavaScript code:

function minSubarray(nums, p) {
    let sum = 0;
    for(let num of nums) {
        sum += num;
    }
    if(sum % p === 0) {
        return 0;
    }
    sum = sum % p;
    let minLen = Infinity;
    let prefixSum = 0;
    let map = new Map();
    map.set(0, -1);
    for(let i = 0; i < nums.length; i++) {
        prefixSum += nums[i];
        prefixSum %= p;
        if(map.has(prefixSum) && minLen > i - map.get(prefixSum)) {
            minLen = i - map.get(prefixSum);
        } else if(!map.has(prefixSum)) {
            map.set(prefixSum, i);
        }
    }
    if(minLen === Infinity) {
        return -1;
    }
    return minLen;
}

In this code, we are first calculating the sum of the array. Then we are checking if this sum is divisible by p. If not, we are returning -1.

If the sum is divisible by p, we are then going through the array and calculating the prefix sums. For each prefix sum, we are checking if there exists a shorter subarray where the sum is divisible by p. If such an answer exists, we are updating the minimum length.

If no such answer is found, we are returning -1.

Otherwise, we are returning the minimum length found.

Please note that this code assumes that the input is a valid array of integers and a valid integer for p. There is no error handling for these conditions.