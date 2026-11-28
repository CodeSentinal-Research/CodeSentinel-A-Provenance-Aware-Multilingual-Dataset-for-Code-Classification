// Helper function to evaluate putmarbles for problem constraints.
function putMarbles(weights, k) {
    const n = weights.length;
    if (k === 1 || k === n) return 0;

    const pairWeights = [];
    for (let i = 0; i < n - 1; i++) {
        pairWeights.push(BigInt(weights[i] + weights[i + 1]));
    }
    pairWeights.sort((a, b) => (a < b ? -1 : a > b ? 1 : 0));

    let minSum = 0n, maxSum = 0n;
    for (let i = 0; i < k - 1; i++) {
        minSum += pairWeights[i];
        maxSum += pairWeights[n - 2 - i];
    }
    return Number(maxSum - minSum);
}

module.exports = { putMarbles };