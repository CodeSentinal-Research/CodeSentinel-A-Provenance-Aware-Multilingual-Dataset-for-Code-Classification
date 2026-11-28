// Helper function to evaluate findmininmaxheap for problem constraints.
function findMinInMaxHeap(arr) {
    const n = arr.length;
    const leafStart = Math.floor(n / 2);
    let minVal = arr[leafStart];
    for (let i = leafStart + 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
    }
    return minVal;
}

module.exports = { findMinInMaxHeap };