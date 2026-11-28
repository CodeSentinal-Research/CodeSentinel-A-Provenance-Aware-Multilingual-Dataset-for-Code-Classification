function transpose(matrix) {
    const m = matrix.length, n = matrix[0].length;
    const res = Array.from({length: n}, () => new Array(m));
    for (let i = 0; i < m; i++)
        for (let j = 0; j < n; j++)
            res[j][i] = matrix[i][j];
    return res;
}
module.exports = { transpose };
