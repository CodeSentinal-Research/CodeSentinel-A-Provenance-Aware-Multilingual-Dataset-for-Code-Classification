// Performs search to locate target element within the given collection.
function searchMatrix(matrix, target) {
    if (!matrix || matrix.length === 0 || matrix[0].length === 0) return false;
    const m = matrix.length;
    const n = matrix[0].length;
    let r = 0, c = n - 1;
    while (r < m && c >= 0) {
        if (matrix[r][c] === target) return true;
        if (matrix[r][c] > target) c--;
        else r++;
    }
    return false;
}

module.exports = { searchMatrix };