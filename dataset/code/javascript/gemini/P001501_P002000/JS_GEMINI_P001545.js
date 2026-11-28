// Helper function to evaluate minmaxmindiffwindow for problem constraints.
function minMaxMinDiffWindow(nums, k) {
    const maxDq = [], minDq = [];
    let minDiff = Infinity;

    for (let i = 0; i < nums.length; i++) {
        while (maxDq.length && nums[maxDq[maxDq.length - 1]] <= nums[i]) maxDq.pop();
        while (minDq.length && nums[minDq[minDq.length - 1]] >= nums[i]) minDq.pop();
        maxDq.push(i);
        minDq.push(i);

        while (maxDq[0] <= i - k) maxDq.shift();
        while (minDq[0] <= i - k) minDq.shift();

        if (i >= k - 1) {
            minDiff = Math.min(minDiff, nums[maxDq[0]] - nums[minDq[0]]);
        }
    }
    return minDiff;
}

module.exports = { minMaxMinDiffWindow };