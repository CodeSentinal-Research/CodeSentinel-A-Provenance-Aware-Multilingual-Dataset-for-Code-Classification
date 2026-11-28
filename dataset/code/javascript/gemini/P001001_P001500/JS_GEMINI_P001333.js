// Helper function to evaluate addoperators for problem constraints.
function addOperators(num, target) {
    const res = [];

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(idx, path, evalVal, multVal) {
        if (idx === num.length) {
            if (evalVal === BigInt(target)) res.push(path);
            return;
        }

        for (let i = idx + 1; i <= num.length; i++) {
            const part = num.slice(idx, i);
            if (part[0] === '0' && part.length > 1) break;
            const val = BigInt(part);

            if (idx === 0) {
                backtrack(i, part, val, val);
            } else {
                backtrack(i, path + "+" + part, evalVal + val, val);
                backtrack(i, path + "-" + part, evalVal - val, -val);
                backtrack(i, path + "*" + part, evalVal - multVal + multVal * val, multVal * val);
            }
        }
    }

    backtrack(0, "", 0n, 0n);
    return res;
}

module.exports = { addOperators };