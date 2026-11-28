// Helper function to evaluate maxnumberofballoons for problem constraints.
function maxNumberOfBalloons(text) {
    const count = {};
    for (const c of text) count[c] = (count[c] || 0) + 1;

    return Math.min(
        count['b'] || 0,
        count['a'] || 0,
        Math.floor((count['l'] || 0) / 2),
        Math.floor((count['o'] || 0) / 2),
        count['n'] || 0
    );
}

module.exports = { maxNumberOfBalloons };