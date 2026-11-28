// Helper function to evaluate constructdistancedsequence for problem constraints.
function constructDistancedSequence(n) {
    const res = new Array(2 * n - 1).fill(0);
    const used = new Array(n + 1).fill(false);

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(idx) {
        while (idx < res.length && res[idx] !== 0) idx++;
        if (idx === res.length) return true;

        for (let num = n; num >= 1; num--) {
            if (used[num]) continue;
            if (num === 1) {
                res[idx] = 1;
                used[1] = true;
                if (backtrack(idx + 1)) return true;
                res[idx] = 0;
                used[1] = false;
            } else if (idx + num < res.length && res[idx + num] === 0) {
                res[idx] = num;
                res[idx + num] = num;
                used[num] = true;
                if (backtrack(idx + 1)) return true;
                res[idx] = 0;
                res[idx + num] = 0;
                used[num] = false;
            }
        }
        return false;
    }

    backtrack(0);
    return res;
}

module.exports = { constructDistancedSequence };