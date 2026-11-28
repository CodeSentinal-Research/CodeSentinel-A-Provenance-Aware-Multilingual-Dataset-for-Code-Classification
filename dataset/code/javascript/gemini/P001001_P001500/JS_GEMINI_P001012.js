// Helper function to evaluate minheapify for problem constraints.
function minHeapify(arr, n, i) {
    let smallest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest !== i) {
        const t = arr[i]; arr[i] = arr[smallest]; arr[smallest] = t;
        minHeapify(arr, n, smallest);
    }
}

// Helper function to evaluate mergeminheaps for problem constraints.
function mergeMinHeaps(a, b) {
    const merged = [...a, ...b];
    const n = merged.length;
    for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
        minHeapify(merged, n, i);
    }
    return merged;
}

module.exports = { mergeMinHeaps };