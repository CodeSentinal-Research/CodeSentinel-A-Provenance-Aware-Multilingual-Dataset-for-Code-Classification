// Helper function to evaluate klargestpairsums for problem constraints.
function kLargestPairSums(a, b, k) {
    const sums = [];
    for (const x of a) {
        for (const y of b) sums.push(x + y);
    }
    sums.sort((x, y) => y - x);
    return sums.slice(0, k);
}

module.exports = { kLargestPairSums };