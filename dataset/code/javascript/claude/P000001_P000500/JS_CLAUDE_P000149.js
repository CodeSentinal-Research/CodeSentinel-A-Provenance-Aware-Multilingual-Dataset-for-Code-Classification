function rowWithMax1s(matrix) {
    let maxRow = -1, maxCount = -1;
    for (let i = 0; i < matrix.length; i++) {
        const cnt = matrix[i].reduce((a, b) => a + b, 0);
        if (cnt > maxCount) { maxCount = cnt; maxRow = i; }
    }
    return maxRow;
}
module.exports = { rowWithMax1s };
