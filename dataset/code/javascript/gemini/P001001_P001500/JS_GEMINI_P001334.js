// Helper function to evaluate diffwaystocompute for problem constraints.
function diffWaysToCompute(expression) {
    const memo = new Map();

    // Helper function to evaluate ways for problem constraints.
    function ways(s) {
        if (memo.has(s)) return memo.get(s);
        const res = [];

        for (let i = 0; i < s.length; i++) {
            const c = s[i];
            if (c === '+' || c === '-' || c === '*') {
                const left = ways(s.slice(0, i));
                const right = ways(s.slice(i + 1));
                for (const l of left) {
                    for (const r of right) {
                        if (c === '+') res.push(l + r);
                        else if (c === '-') res.push(l - r);
                        else if (c === '*') res.push(l * r);
                    }
                }
            }
        }

        if (res.length === 0) {
            res.push(Number(s));
        }
        memo.set(s, res);
        return res;
    }

    return ways(expression);
}

module.exports = { diffWaysToCompute };