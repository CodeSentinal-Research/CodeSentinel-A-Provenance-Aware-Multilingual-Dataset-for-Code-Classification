function countTriplets(nums, target) {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let count = 0;
    for (let i = 0; i < n - 2; i++) {
        let l = i + 1, r = n - 1;
        while (l < r) {
            const curSum = nums[i] + nums[l] + nums[r];
            if (curSum === target) {
                count++;
                l++;
                r--;
            } else if (curSum < target) {
                l++;
            } else {
                r--;
            }
        }
    }
    return count;
}

module.exports = { countTriplets };