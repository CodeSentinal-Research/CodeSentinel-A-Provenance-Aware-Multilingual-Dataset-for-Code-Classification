class NumMatrix {
    constructor(matrix) {
        if (!matrix.length || !matrix[0].length) return;
        const m = matrix.length, n = matrix[0].length;
        this.p = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));

        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                this.p[i + 1][j + 1] = matrix[i][j] + this.p[i][j + 1] + this.p[i + 1][j] - this.p[i][j];
            }
        }
    }

    sumRegion(row1, col1, row2, col2) {
        return this.p[row2 + 1][col2 + 1] - this.p[row1][col2 + 1] - this.p[row2 + 1][col1] + this.p[row1][col1];
    }
}

module.exports = { NumMatrix };