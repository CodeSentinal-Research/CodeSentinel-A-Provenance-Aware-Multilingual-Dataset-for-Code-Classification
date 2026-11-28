// Helper function to evaluate isvalidmaxheap for problem constraints.
function isValidMaxHeap(arr) {
    const n = arr.length;
    for (let i = 0; i <= Math.floor((n - 2) / 2); i++) {
        const left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && arr[i] < arr[left]) return false;
        if (right < n && arr[i] < arr[right]) return false;
    }
    return true;
}

module.exports = { isValidMaxHeap };