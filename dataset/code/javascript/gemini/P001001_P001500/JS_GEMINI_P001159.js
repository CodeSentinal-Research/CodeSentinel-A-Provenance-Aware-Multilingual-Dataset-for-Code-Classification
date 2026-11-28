// Helper function to evaluate numdecodings for problem constraints.
function numDecodings(s) {
    if (!s || s[0] === '0') return 0;
    let a = 1, b = 1;
    for (let i = 1; i < s.length; i++) {
        let c = 0;
        if (s[i] !== '0') c += b;
        const two = parseInt(s.slice(i - 1, i + 1), 10);
        if (two >= 10 && two <= 26) c += a;
        a = b;
        b = c;
    }
    return b;
}

module.exports = { numDecodings };