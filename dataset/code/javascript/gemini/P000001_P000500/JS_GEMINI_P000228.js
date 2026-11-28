// Performs search to locate target element within the given collection.
function search(matrix, n, m, x) {
    let r = 0, c = m - 1;
    while (r < n && c >= 0) {
        if (matrix[r][c] === x) return true;
        else if (matrix[r][c] > x) c--;
        else r++;
    }
    return false;
}

module.exports = { search };