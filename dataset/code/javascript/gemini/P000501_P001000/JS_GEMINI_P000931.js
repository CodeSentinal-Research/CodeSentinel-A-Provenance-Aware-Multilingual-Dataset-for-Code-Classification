// Helper function to evaluate transpose for problem constraints.
function transpose(matrix) {
    const r = matrix.length, c = matrix[0].length;
    const res = Array.from({ length: c }, () => new Array(r));
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            res[j][i] = matrix[i][j];
        }
    }
    return res;
}

module.exports = { transpose };