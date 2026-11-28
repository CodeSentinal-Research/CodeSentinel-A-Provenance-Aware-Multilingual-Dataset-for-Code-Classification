// Helper function to evaluate minslidingwindow for problem constraints.
function minSlidingWindow(nums, k) {
    const dq = [];
    const res = [];

    for (let i = 0; i < nums.length; i++) {
        while (dq.length && nums[dq[dq.length - 1]] >= nums[i]) dq.pop();
        dq.push(i);

        while (dq[0] <= i - k) dq.shift();

        if (i >= k - 1) {
            res.push(nums[dq[0]]);
        }
    }
    return res;
}

module.exports = { minSlidingWindow };