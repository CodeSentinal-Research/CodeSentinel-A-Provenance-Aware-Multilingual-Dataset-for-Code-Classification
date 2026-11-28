// Helper function to evaluate subsetswithdup for problem constraints.
function subsetsWithDup(nums) {
    nums.sort((a, b) => a - b);
    const res = [];

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(idx, cur) {
        res.push([...cur]);
        for (let i = idx; i < nums.length; i++) {
            if (i > idx && nums[i] === nums[i - 1]) continue;
            cur.push(nums[i]);
            backtrack(i + 1, cur);
            cur.pop();
        }
    }

    backtrack(0, []);
    return res;
}

module.exports = { subsetsWithDup };