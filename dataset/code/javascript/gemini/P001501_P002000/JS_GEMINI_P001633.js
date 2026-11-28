// Helper function to evaluate maxsumsubmatrix for problem constraints.
function maxSumSubmatrix(matrix, k) {
    const m = matrix.length, n = matrix[0].length;
    let maxSum = -Infinity;

    for (let l = 0; l < n; l++) {
        const rowSum = new Array(m).fill(0);
        for (let r = l; r < n; r++) {
            for (let i = 0; i < m; i++) rowSum[i] += matrix[i][r];

            for (let i = 0; i < m; i++) {
                let cur = 0;
                for (let j = i; j < m; j++) {
                    cur += rowSum[j];
                    if (cur <= k) maxSum = Math.max(maxSum, cur);
                }
            }
        }
    }
    return maxSum;
}

module.exports = { maxSumSubmatrix };