function findMaxValue(mat, N) {
    const maxArr = Array.from({ length: N }, () => new Array(N).fill(0));
    maxArr[N - 1][N - 1] = mat[N - 1][N - 1];

    let maxV = mat[N - 1][N - 1];
    for (let j = N - 2; j >= 0; j--) {
        maxV = Math.max(maxV, mat[N - 1][j]);
        maxArr[N - 1][j] = maxV;
    }

    maxV = mat[N - 1][N - 1];
    for (let i = N - 2; i >= 0; i--) {
        maxV = Math.max(maxV, mat[i][N - 1]);
        maxArr[i][N - 1] = maxV;
    }

    let maxDiff = -Infinity;

    for (let i = N - 2; i >= 0; i--) {
        for (let j = N - 2; j >= 0; j--) {
            if (maxArr[i + 1][j + 1] - mat[i][j] > maxDiff) {
                maxDiff = maxArr[i + 1][j + 1] - mat[i][j];
            }
            maxArr[i][j] = Math.max(mat[i][j], maxArr[i + 1][j], maxArr[i][j + 1]);
        }
    }
    return maxDiff;
}

module.exports = { findMaxValue };