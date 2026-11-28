// Helper function to evaluate sumdigitsupto for problem constraints.
function sumDigitsUpTo(n) {
    if (n <= 0) return 0;
    const s = n.toString();
    const d = s.length;
    if (d === 1) return (n * (n + 1)) / 2;
    const first = parseInt(s[0], 10);
    const rem = parseInt(s.substring(1) || "0", 10);
    const p = Math.pow(10, d - 1);

    let ans = first * 45 * (d - 1) * (p / 10);
    ans += ((first * (first - 1)) / 2) * p;
    ans += first * (rem + 1);
    ans += sumDigitsUpTo(rem);
    return ans;
}

// Helper function to evaluate sumdigitsrange for problem constraints.
function sumDigitsRange(l, r) {
    return sumDigitsUpTo(r) - sumDigitsUpTo(l - 1);
}

module.exports = { sumDigitsRange };