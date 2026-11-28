// Helper function to evaluate combinationsum2 for problem constraints.
function combinationSum2(candidates, target) {
    candidates.sort((a, b) => a - b);
    const res = [];

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(idx, cur, curSum) {
        if (curSum === target) {
            res.push([...cur]);
            return;
        }
        if (curSum > target) return;

        for (let i = idx; i < candidates.length; i++) {
            if (i > idx && candidates[i] === candidates[i - 1]) continue;
            cur.push(candidates[i]);
            backtrack(i + 1, cur, curSum + candidates[i]);
            cur.pop();
        }
    }

    backtrack(0, [], 0);
    return res;
}

module.exports = { combinationSum2 };