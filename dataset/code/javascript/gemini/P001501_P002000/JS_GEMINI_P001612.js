// Helper function to evaluate canthreepartsequalsum for problem constraints.
function canThreePartsEqualSum(arr) {
    const total = arr.reduce((a, b) => a + b, 0);
    if (total % 3 !== 0) return false;

    const target = total / 3;
    let curSum = 0, count = 0;

    for (const x of arr) {
        curSum += x;
        if (curSum === target) {
            count++;
            curSum = 0;
        }
    }
    return count >= 3;
}

module.exports = { canThreePartsEqualSum };