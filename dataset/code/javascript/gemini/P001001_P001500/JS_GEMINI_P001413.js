// Helper function to evaluate largestuniquenumber for problem constraints.
function largestUniqueNumber(nums) {
    const map = new Map();
    for (const x of nums) map.set(x, (map.get(x) || 0) + 1);

    let maxVal = -1;
    for (const [x, cnt] of map.entries()) {
        if (cnt === 1) {
            if (x > maxVal) maxVal = x;
        }
    }
    return maxVal;
}

module.exports = { largestUniqueNumber };