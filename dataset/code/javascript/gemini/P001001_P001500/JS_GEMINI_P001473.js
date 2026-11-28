// Helper function to evaluate threesumclosest for problem constraints.
function threeSumClosest(nums, target) {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let closestSum = nums[0] + nums[1] + nums[2];

    for (let i = 0; i < n - 2; i++) {
        let l = i + 1, r = n - 1;
        while (l < r) {
            const sum = nums[i] + nums[l] + nums[r];
            if (Math.abs(sum - target) < Math.abs(closestSum - target)) {
                closestSum = sum;
            }
            if (sum < target) l++;
            else if (sum > target) r--;
            else return target;
        }
    }
    return closestSum;
}

module.exports = { threeSumClosest };