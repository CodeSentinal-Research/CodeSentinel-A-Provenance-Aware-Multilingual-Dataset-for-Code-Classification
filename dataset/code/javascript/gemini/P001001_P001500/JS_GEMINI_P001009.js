// Helper function to evaluate maxheapify for problem constraints.
function maxHeapify(arr, n, i) {
    let largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest !== i) {
        const t = arr[i]; arr[i] = arr[largest]; arr[largest] = t;
        maxHeapify(arr, n, largest);
    }
}

// Helper function to evaluate deleteroot for problem constraints.
function deleteRoot(arr) {
    if (arr.length === 0) return [];
    const last = arr.pop();
    if (arr.length > 0) {
        arr[0] = last;
        maxHeapify(arr, arr.length, 0);
    }
    return arr;
}

module.exports = { deleteRoot };