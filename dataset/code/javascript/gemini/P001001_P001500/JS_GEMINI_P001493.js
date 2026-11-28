// Helper function to evaluate shortesttochar for problem constraints.
function shortestToChar(s, c) {
    const n = s.length;
    const res = new Array(n);
    let pos = -n;

    for (let i = 0; i < n; i++) {
        if (s[i] === c) pos = i;
        res[i] = i - pos;
    }

    pos = 2 * n;
    for (let i = n - 1; i >= 0; i--) {
        if (s[i] === c) pos = i;
        res[i] = Math.min(res[i], pos - i);
    }
    return res;
}

module.exports = { shortestToChar };