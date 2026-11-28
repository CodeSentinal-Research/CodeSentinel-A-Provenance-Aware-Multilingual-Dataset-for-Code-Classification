function findSaddlePoint(matrix) {
    const n = matrix.length;
    for (let i = 0; i < n; i++) {
        let minRow = matrix[i][0];
        let colIdx = 0;
        for (let j = 1; j < n; j++) {
            if (matrix[i][j] < minRow) {
                minRow = matrix[i][j];
                colIdx = j;
            }
        }

        let isSaddle = true;
        for (let k = 0; k < n; k++) {
            if (matrix[k][colIdx] > minRow) {
                isSaddle = false;
                break;
            }
        }

        if (isSaddle) return minRow;
    }
    return -1;
}

module.exports = { findSaddlePoint };