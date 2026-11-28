// Helper function to evaluate countderangements for problem constraints.
function countDerangements(n) {
    if (n === 0) return 1;
    if (n === 1) return 0;
    let prev2 = 1, prev1 = 0;
    for (let i = 2; i <= n; i++) {
        let curr = (i - 1) * (prev1 + prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

module.exports = { countDerangements };