// Helper function to evaluate heapify for problem constraints.
function heapify(arr, n, i) {
    let largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest !== i) {
        const t = arr[i]; arr[i] = arr[largest]; arr[largest] = t;
        heapify(arr, n, largest);
    }
}

// Sorts the input array into ordered sequence.
function sortArray(nums) {
    const n = nums.length;
    for (let i = Math.floor(n / 2) - 1; i >= 0; i--) {
        heapify(nums, n, i);
    }
    for (let i = n - 1; i > 0; i--) {
        const t = nums[0]; nums[0] = nums[i]; nums[i] = t;
        heapify(nums, i, 0);
    }
    return nums;
}

module.exports = { sortArray };