// Helper function to evaluate generateparenthesis for problem constraints.
function generateParenthesis(n) {
    const res = [];

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(open, close, cur) {
        if (cur.length === 2 * n) {
            res.push(cur);
            return;
        }
        if (open < n) {
            backtrack(open + 1, close, cur + "(");
        }
        if (close < open) {
            backtrack(open, close + 1, cur + ")");
        }
    }

    backtrack(0, 0, "");
    return res;
}

module.exports = { generateParenthesis };