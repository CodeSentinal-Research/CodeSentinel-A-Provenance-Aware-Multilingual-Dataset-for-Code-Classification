// Helper function to evaluate maxsumrectangle for problem constraints.
function maxSumRectangle(mat) {
    const m = mat.length, n = mat[0].length;
    let maxSum = -Infinity;

    for (let left = 0; left < n; left++) {
        const rowSum = new Array(m).fill(0);
        for (let right = left; right < n; right++) {
            for (let i = 0; i < m; i++) rowSum[i] += mat[i][right];

            let curMax = rowSum[0];
            let curSum = 0;
            for (const x of rowSum) {
                curSum = Math.max(x, curSum + x);
                curMax = Math.max(curMax, curSum);
            }
            maxSum = Math.max(maxSum, curMax);
        }
    }
    return maxSum;
}

module.exports = { maxSumRectangle };