function rowWithMax1s(matrix) {
    if (!matrix.length || !matrix[0].length) return -1;
    const m = matrix.length, n = matrix[0].length;
    let r = 0, c = n - 1;
    let maxRow = -1;

    while (r < m && c >= 0) {
        if (matrix[r][c] === 1) {
            maxRow = r;
            c--;
        } else {
            r++;
        }
    }
    return maxRow;
}

module.exports = { rowWithMax1s };