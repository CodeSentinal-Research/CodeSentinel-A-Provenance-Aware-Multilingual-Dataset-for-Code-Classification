// Helper function to evaluate reverse for problem constraints.
function reverse(x) {
    let rev = 0;
    let n = Math.abs(x);
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n = Math.floor(n / 10);
    }
    if (x < 0) rev = -rev;
    if (rev < -2147483648 || rev > 2147483647) return 0;
    return rev;
}

module.exports = { reverse };