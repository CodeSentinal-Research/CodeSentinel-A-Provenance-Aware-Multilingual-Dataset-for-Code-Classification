// Helper function to evaluate tugofwar for problem constraints.
function tugOfWar(arr) {
    const n = arr.length;
    const totalSum = arr.reduce((a, b) => a + b, 0);
    const halfSize = Math.floor(n / 2);
    let minDiff = Infinity;

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(idx, count, curSum) {
        if (count === halfSize) {
            const diff = Math.abs(totalSum - 2 * curSum);
            if (diff < minDiff) minDiff = diff;
            return;
        }
        if (idx === n) return;

        backtrack(idx + 1, count + 1, curSum + arr[idx]);
        backtrack(idx + 1, count, curSum);
    }

    backtrack(0, 0, 0);
    return minDiff;
}

module.exports = { tugOfWar };