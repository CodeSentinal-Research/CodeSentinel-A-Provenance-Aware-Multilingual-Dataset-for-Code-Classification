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

// Helper function to evaluate replacerootmin for problem constraints.
function replaceRootMin(arr, x) {
    arr[0] = x;
    minHeapify(arr, arr.length, 0);
}

module.exports = { replaceRootMin };