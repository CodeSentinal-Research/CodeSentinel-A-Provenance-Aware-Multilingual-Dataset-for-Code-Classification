Here is a JavaScript solution for the given problem:

function checkSubarraySum(nums, k) {
    let map = new Map();
    let sum = 0;
    map.set(0, -1);
    for (let i = 0; i < nums.length; i++) {
        sum += nums[i];
        sum %= k;
        if (map.has(sum) && i - map.get(sum) >= 2) {
            return true;
        }
        if (!map.has(sum)) {
            map.set(sum, i);
        }
    }
    return false;
}
This code first initializes a Map named `map` and a variable `sum`. The map stores the prefix sum as the key and its index as the value. In the loop, the prefix sum is calculated by adding the current element to the sum. If the sum mod k is 0, that means the sum is a multiple of k. Then, the code checks if the map already contains the sum. If it does, and the difference between the current index and the index stored in the map (which corresponds to the previous index of the sum) is at least 2, it means there is a continuous subarray sum of length at least 2 whose sum is a multiple of k. Otherwise, it updates the sum in the map. If the sum does not exist in the map, it adds the sum to the map.