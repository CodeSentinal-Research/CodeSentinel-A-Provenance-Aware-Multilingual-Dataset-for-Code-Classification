// Helper function to evaluate kthsmallest for problem constraints.
function kthSmallest(matrix, k) {
    const arr = [];
    for (const row of matrix) arr.push(...row);
    arr.sort((a, b) => a - b);
    return arr[k - 1];
}

module.exports = { kthSmallest };