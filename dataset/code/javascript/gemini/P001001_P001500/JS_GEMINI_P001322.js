// Helper function to evaluate combinationsum for problem constraints.
function combinationSum(candidates, target) {
    const res = [];

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(idx, cur, curSum) {
        if (curSum === target) {
            res.push([...cur]);
            return;
        }
        if (curSum > target || idx === candidates.length) return;

        cur.push(candidates[idx]);
        backtrack(idx, cur, curSum + candidates[idx]);
        cur.pop();

        backtrack(idx + 1, cur, curSum);
    }

    backtrack(0, [], 0);
    return res;
}

module.exports = { combinationSum };