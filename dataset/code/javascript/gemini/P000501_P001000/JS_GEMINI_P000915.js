// Helper function to evaluate counthandshakes for problem constraints.
function countHandshakes(n) {
    if (n % 2 === 1) return 0;
    const k = Math.floor(n / 2);
    let ans = 1;
    for (let i = 0; i < k; i++) {
        ans = Math.round((ans * (2 * k - i)) / (i + 1));
    }
    return Math.floor(ans / (k + 1));
}

module.exports = { countHandshakes };