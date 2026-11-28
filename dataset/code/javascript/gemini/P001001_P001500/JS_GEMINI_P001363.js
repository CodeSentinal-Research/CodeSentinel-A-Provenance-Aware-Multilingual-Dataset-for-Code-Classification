// Helper function to evaluate validstrings for problem constraints.
function validStrings(n) {
    const res = [];

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(cur) {
        if (cur.length === n) {
            res.push(cur);
            return;
        }
        backtrack(cur + "1");
        if (cur.length === 0 || cur[cur.length - 1] !== '0') {
            backtrack(cur + "0");
        }
    }

    backtrack("");
    return res;
}

module.exports = { validStrings };