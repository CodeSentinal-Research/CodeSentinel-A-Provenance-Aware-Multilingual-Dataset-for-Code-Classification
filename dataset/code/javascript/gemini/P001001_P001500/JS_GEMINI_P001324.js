// Helper function to evaluate combinationsum3 for problem constraints.
function combinationSum3(k, n) {
    const res = [];

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(start, cur, curSum) {
        if (cur.length === k) {
            if (curSum === n) res.push([...cur]);
            return;
        }
        for (let i = start; i <= 9; i++) {
            if (curSum + i > n) break;
            cur.push(i);
            backtrack(i + 1, cur, curSum + i);
            cur.pop();
        }
    }

    backtrack(1, [], 0);
    return res;
}

module.exports = { combinationSum3 };