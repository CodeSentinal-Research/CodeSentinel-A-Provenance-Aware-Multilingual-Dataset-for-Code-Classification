function maxLength(nums) {
    let maxLen = 0;
    let dp = new Map();
    dp.set(0, 0);
    let even = 0, odd = 0;

    for (let num of nums) {
        even += num % 2 === 0 ? 1 : 0;
        odd += num % 2 === 1 ? 1 : 0;
        let diff = even - odd;
        if (dp.has(diff)) {
            maxLen = Math.max(maxLen, dp.get(diff) + even - odd);
        } else {
            dp.set(diff, even - odd);
        }
    }
    return maxLen;
}
This code works by maintaining two counters `even` and `odd` for even and odd numbers, and `diff` for the difference of `even` and `odd` counts. The code then uses a `Map` to store the maximum length subarray length at each index. If the difference `diff` is already in the map, it means we have seen this difference before, so we update the maximum length if the current length is greater than the previously stored length. Otherwise, we store the current length in the map.