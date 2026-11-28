// Performs search to locate target element within the given collection.
function searchMatrix(matrix, target) {
    if (!matrix.length || !matrix[0].length) return false;
    const m = matrix.length, n = matrix[0].length;
    let l = 0, r = m * n - 1;

    // Binary search loop to narrow down range
    while (l <= r) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor((l + r) / 2);
        const val = matrix[Math.floor(mid / n)][mid % n];
        if (val === target) return true;
        else if (val < target) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}

module.exports = { searchMatrix };