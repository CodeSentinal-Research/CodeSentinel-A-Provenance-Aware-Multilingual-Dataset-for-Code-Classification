Here's the JavaScript code for the problem. This code takes an array of integers and a target value as input, then counts the number of valid subarrays in the array that contain exactly k odd numbers.

function countOdds(nums, k) {
    let oddCount = 0;
    let validSubarrays = 0;

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] % 2 === 1) {
            oddCount++;
        }
        if (oddCount === k) {
            validSubarrays++;
            oddCount = 0;
        }
    }

    return validSubarrays;
}

This function starts by initializing `oddCount` to 0 and `validSubarrays` to 0. Then it iterates over each element in the array. If the current element is odd, it increments `oddCount`. If `oddCount` equals `k` (the target odd number count), it means we have found a valid subarray with exactly `k` odd numbers, so it increments `validSubarrays` and reset `oddCount` to 0. At the end, it returns the total number of valid subarrays found.