// Helper function to evaluate combine for problem constraints.
function combine(n, k) {
    const res = [];

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(start, cur) {
        if (cur.length === k) {
            res.push([...cur]);
            return;
        }
        for (let i = start; i <= n; i++) {
            cur.push(i);
            backtrack(i + 1, cur);
            cur.pop();
        }
    }

    backtrack(1, []);
    return res;
}

module.exports = { combine };