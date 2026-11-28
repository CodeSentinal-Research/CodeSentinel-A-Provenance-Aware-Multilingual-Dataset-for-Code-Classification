// Helper function to evaluate circulararrangements for problem constraints.
function circularArrangements(n) {
    if (n <= 1) return 1;
    let ans = 1;
    for (let i = 1; i < n; i++) {
        ans *= i;
    }
    return ans;
}

module.exports = { circularArrangements };