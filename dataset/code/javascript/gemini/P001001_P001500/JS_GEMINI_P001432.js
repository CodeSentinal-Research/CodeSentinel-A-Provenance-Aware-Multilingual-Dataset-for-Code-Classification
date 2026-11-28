// Helper function to evaluate numequivdominopairs for problem constraints.
function numEquivDominoPairs(dominoes) {
    const count = new Array(100).fill(0);
    let ans = 0;

    for (const [a, b] of dominoes) {
        const val = a < b ? a * 10 + b : b * 10 + a;
        ans += count[val]++;
    }
    return ans;
}

module.exports = { numEquivDominoPairs };