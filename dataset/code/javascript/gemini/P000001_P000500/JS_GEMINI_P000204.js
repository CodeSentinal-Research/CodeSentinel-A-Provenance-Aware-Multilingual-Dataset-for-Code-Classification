// Sorts the input array into ordered sequence.
function waveSort(arr) {
    const n = arr.length;
    for (let i = 0; i < n - 1; i += 2) {
        if (i > 0 && arr[i] < arr[i - 1]) {
            const temp = arr[i]; arr[i] = arr[i - 1]; arr[i - 1] = temp;
        }
        if (i < n - 1 && arr[i] < arr[i + 1]) {
            const temp = arr[i]; arr[i] = arr[i + 1]; arr[i + 1] = temp;
        }
    }
}

module.exports = { waveSort };