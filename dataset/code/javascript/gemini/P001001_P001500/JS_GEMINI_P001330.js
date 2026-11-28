// Helper function to evaluate partition for problem constraints.
function partition(s) {
    const res = [];

    // Helper function to evaluate ispal for problem constraints.
    function isPal(str) {
        return str === str.split('').reverse().join('');
    }

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(idx, cur) {
        if (idx === s.length) {
            res.push([...cur]);
            return;
        }
        for (let i = idx + 1; i <= s.length; i++) {
            const sub = s.slice(idx, i);
            if (isPal(sub)) {
                cur.push(sub);
                backtrack(i, cur);
                cur.pop();
            }
        }
    }

    backtrack(0, []);
    return res;
}

module.exports = { partition };