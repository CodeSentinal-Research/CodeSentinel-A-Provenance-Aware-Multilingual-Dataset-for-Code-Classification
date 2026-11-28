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

// Helper function to evaluate replacemultiplekeys for problem constraints.
function replaceMultipleKeys(arr, updates) {
    for (const [idx, val] of updates) {
        arr[idx] = val;
    }
    const n = arr.length;
    for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
    return arr;
}

module.exports = { replaceMultipleKeys };