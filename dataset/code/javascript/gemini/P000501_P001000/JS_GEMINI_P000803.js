function numSubmatrixSumTarget(matrix, target) {
    const r = matrix.length;
    const c = matrix[0].length;
    for (let i = 0; i < r; i++) {
        for (let j = 1; j < c; j++) {
            matrix[i][j] += matrix[i][j - 1];
        }
    }

    let count = 0;
    for (let c1 = 0; c1 < c; c1++) {
        for (let c2 = c1; c2 < c; c2++) {
            const map = new Map();
            map.set(0, 1);
            let curSum = 0;
            for (let row = 0; row < r; row++) {
                curSum += matrix[row][c2] - (c1 > 0 ? matrix[row][c1 - 1] : 0);
                count += (map.get(curSum - target) || 0);
                map.set(curSum, (map.get(curSum) || 0) + 1);
            }
        }
    }
    return count;
}

module.exports = { numSubmatrixSumTarget };