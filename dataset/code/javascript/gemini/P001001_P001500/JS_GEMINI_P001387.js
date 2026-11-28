// Helper function to evaluate checkequality for problem constraints.
function checkEquality(a, b) {
    if (a.length !== b.length) return false;
    const count = new Map();
    for (const x of a) count.set(x, (count.get(x) || 0) + 1);

    for (const x of b) {
        if (!count.has(x) || count.get(x) === 0) return false;
        count.set(x, count.get(x) - 1);
    }
    return true;
}

module.exports = { checkEquality };