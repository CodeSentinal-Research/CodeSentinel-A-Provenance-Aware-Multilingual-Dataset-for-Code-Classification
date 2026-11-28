// Helper function to evaluate subsets for problem constraints.
function subsets(nums) {
    const res = [];

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(idx, cur) {
        if (idx === nums.length) {
            res.push([...cur]);
            return;
        }
        cur.push(nums[idx]);
        backtrack(idx + 1, cur);
        cur.pop();

        backtrack(idx + 1, cur);
    }

    backtrack(0, []);
    return res;
}

module.exports = { subsets };