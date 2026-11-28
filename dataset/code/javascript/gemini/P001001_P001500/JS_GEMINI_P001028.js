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

// Helper function to evaluate deleteindex for problem constraints.
function deleteIndex(arr, idx) {
    arr[idx] = arr.pop();
    if (idx < arr.length) {
        let cur = idx;
        while (cur > 0 && arr[cur] > arr[Math.floor((cur - 1) / 2)]) {
            const p = Math.floor((cur - 1) / 2);
            const t = arr[cur]; arr[cur] = arr[p]; arr[p] = t;
            cur = p;
        }
        maxHeapify(arr, arr.length, cur);
    }
    return arr;
}

module.exports = { deleteIndex };