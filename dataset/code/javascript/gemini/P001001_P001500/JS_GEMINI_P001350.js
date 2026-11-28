// Helper function to evaluate gethappystring for problem constraints.
function getHappyString(n, k) {
    const res = [];

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(cur) {
        if (cur.length === n) {
            res.push(cur);
            return;
        }
        for (const c of ['a', 'b', 'c']) {
            if (cur.length === 0 || cur[cur.length - 1] !== c) {
                backtrack(cur + c);
            }
        }
    }

    backtrack("");
    return k <= res.length ? res[k - 1] : "";
}

module.exports = { getHappyString };