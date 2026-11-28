// Performs search to locate target element within the given collection.
function searchMatrix(matrix, target) {
    if (!matrix || matrix.length === 0 || matrix[0].length === 0) return false;
    const m = matrix.length;
    const n = matrix[0].length;
    let left = 0, right = m * n - 1;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        const val = matrix[Math.floor(mid / n)][mid % n];
        if (val === target) return true;
        if (val < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

module.exports = { searchMatrix };