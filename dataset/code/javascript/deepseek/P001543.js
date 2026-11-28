function minWindow(arr, k) {
    let n = arr.length;
    if (n < k) {
        return -1;
    }
    let sum = 0;
    for (let i = 0; i < n; i++) {
        sum += arr[i];
    }
    if (sum < k) {
        return -1;
    }
    sum = 0;
    let minWindowSum = Number.MAX_SAFE_INTEGER;
    for (let i = 0; i < n; i++) {
        sum += arr[i];
        if (sum >= k) {
            minWindowSum = Math.min(minWindowSum, sum);
        }
        if (i >= k - 1) {
            sum -= arr[i - (k - 1)];
        }
    }
    return minWindowSum;
}