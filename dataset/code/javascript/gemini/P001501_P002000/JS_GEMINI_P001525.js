// Helper function to evaluate longestevenoddsubarray for problem constraints.
function longestEvenOddSubarray(arr) {
    const diffMap = new Map();
    diffMap.set(0, -1);
    let diff = 0, maxLen = 0;

    for (let i = 0; i < arr.length; i++) {
        diff += (arr[i] % 2 === 0) ? 1 : -1;
        if (diffMap.has(diff)) {
            maxLen = Math.max(maxLen, i - diffMap.get(diff));
        } else {
            diffMap.set(diff, i);
        }
    }
    return maxLen;
}

module.exports = { longestEvenOddSubarray };