function booleanMatrix(matrix) {
    const R = matrix.length, C = matrix[0].length;
    const rowFlag = new Array(R).fill(0);
    const colFlag = new Array(C).fill(0);

    for (let i = 0; i < R; i++) {
        for (let j = 0; j < C; j++) {
            if (matrix[i][j] === 1) {
                rowFlag[i] = 1;
                colFlag[j] = 1;
            }
        }
    }

    for (let i = 0; i < R; i++) {
        for (let j = 0; j < C; j++) {
            if (rowFlag[i] === 1 || colFlag[j] === 1) {
                matrix[i][j] = 1;
            }
        }
    }
}

module.exports = { booleanMatrix };