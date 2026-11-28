function maxSumIS(arr, n) {
    const msis = [...arr];
    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i]) {
                msis[i] = msis[j] + arr[i];
            }
        }
    }
    return Math.max(...msis);
}

module.exports = { maxSumIS };