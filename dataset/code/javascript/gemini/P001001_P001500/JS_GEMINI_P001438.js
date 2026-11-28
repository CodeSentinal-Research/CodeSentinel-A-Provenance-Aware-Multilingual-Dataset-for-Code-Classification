// Helper function to evaluate dividearray for problem constraints.
function divideArray(nums) {
    const count = new Map();
    for (const x of nums) count.set(x, (count.get(x) || 0) + 1);
    for (const cnt of count.values()) {
        if (cnt % 2 !== 0) return false;
    }
    return true;
}

module.exports = { divideArray };