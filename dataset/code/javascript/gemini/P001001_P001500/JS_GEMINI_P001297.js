// Helper function to evaluate maximizesumoneswap for problem constraints.
function maximizeSumOneSwap(arr) {
    const n = arr.length;
    let baseSum = 0n;
    for (let i = 0; i < n; i++) {
        baseSum += BigInt(i) * BigInt(arr[i]);
    }
    let maxSum = baseSum;

    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const gain = BigInt(j - i) * BigInt(arr[i]) + BigInt(i - j) * BigInt(arr[j]);
            if (baseSum + gain > maxSum) maxSum = baseSum + gain;
        }
    }
    return Number(maxSum);
}

module.exports = { maximizeSumOneSwap };