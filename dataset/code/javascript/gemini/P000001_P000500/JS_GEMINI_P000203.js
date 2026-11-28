function maxRepeating(arr, n, k) {
    for (let i = 0; i < n; i++) {
        arr[arr[i] % k] += k;
    }

    let maxVal = arr[0], result = 0;
    for (let i = 1; i < k; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            result = i;
        }
    }
    return result;
}

module.exports = { maxRepeating };