function rotateMatrix(M, N, mat) {
    let row = 0, col = 0;
    let m = M, n = N;

    while (row < m && col < n) {
        if (row + 1 === m || col + 1 === n) break;

        let prev = mat[row + 1][col];

        for (let i = col; i < n; i++) {
            const curr = mat[row][i];
            mat[row][i] = prev;
            prev = curr;
        }
        row++;

        for (let i = row; i < m; i++) {
            const curr = mat[i][n - 1];
            mat[i][n - 1] = prev;
            prev = curr;
        }
        n--;

        if (row < m) {
            for (let i = n - 1; i >= col; i--) {
                const curr = mat[m - 1][i];
                mat[m - 1][i] = prev;
                prev = curr;
            }
            m--;
        }

        if (col < n) {
            for (let i = m - 1; i >= row; i--) {
                const curr = mat[i][col];
                mat[i][col] = prev;
                prev = curr;
            }
            col++;
        }
    }
    return mat;
}

module.exports = { rotateMatrix };