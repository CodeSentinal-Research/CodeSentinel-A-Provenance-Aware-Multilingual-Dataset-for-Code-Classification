// Helper function to evaluate permuteunique for problem constraints.
function permuteUnique(nums) {
    nums.sort((a, b) => a - b);
    const res = [];
    const visited = new Array(nums.length).fill(false);

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(cur) {
        if (cur.length === nums.length) {
            res.push([...cur]);
            return;
        }
        for (let i = 0; i < nums.length; i++) {
            if (visited[i]) continue;
            if (i > 0 && nums[i] === nums[i - 1] && !visited[i - 1]) continue;

            visited[i] = true;
            cur.push(nums[i]);
            backtrack(cur);
            cur.pop();
            visited[i] = false;
        }
    }

    backtrack([]);
    return res;
}

module.exports = { permuteUnique };