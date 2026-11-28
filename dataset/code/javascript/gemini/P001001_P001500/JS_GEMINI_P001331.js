// Helper function to evaluate restoreipaddresses for problem constraints.
function restoreIpAddresses(s) {
    const res = [];

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(idx, dots, cur) {
        if (dots === 4 && idx === s.length) {
            res.push(cur.slice(0, -1));
            return;
        }
        if (dots > 4) return;

        for (let l = 1; l <= 3; l++) {
            if (idx + l <= s.length) {
                const part = s.slice(idx, idx + l);
                if ((part[0] !== '0' || l === 1) && Number(part) <= 255) {
                    backtrack(idx + l, dots + 1, cur + part + ".");
                }
            }
        }
    }

    backtrack(0, 0, "");
    return res;
}

module.exports = { restoreIpAddresses };