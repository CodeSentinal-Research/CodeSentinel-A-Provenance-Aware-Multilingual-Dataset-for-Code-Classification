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

// Helper function to evaluate mergemaxheaps for problem constraints.
function mergeMaxHeaps(a, b) {
    const merged = [...a, ...b];
    const n = merged.length;
    for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
        maxHeapify(merged, n, i);
    }
    return merged;
}

module.exports = { mergeMaxHeaps };