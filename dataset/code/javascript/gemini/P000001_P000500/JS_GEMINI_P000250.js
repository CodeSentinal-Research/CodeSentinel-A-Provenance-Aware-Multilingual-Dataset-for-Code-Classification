function determinantOfMatrix(matrix, n) {
    if (n === 1) return matrix[0][0];
    if (n === 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    let det = 0;
    for (let p = 0; p < n; p++) {
        const sub = [];
        for (let i = 1; i < n; i++) {
            const subRow = [];
            for (let j = 0; j < n; j++) {
                if (j !== p) subRow.push(matrix[i][j]);
            }
            sub.push(subRow);
        }
        const sign = p % 2 === 0 ? 1 : -1;
        det += sign * matrix[0][p] * determinantOfMatrix(sub, n - 1);
    }
    return det;
}

module.exports = { determinantOfMatrix };