function maxCandies(n, arr, k) {
    arr.sort((a, b) => b - a);
    let maxCandies = 0;
    for (let i = 0; i < n; i++) {
        maxCandies += arr[i];
        if (i < k - 1) {
            maxCandies += arr[i+1];
        }
    }
    maxCandies -= Math.max(...arr) * (k - 1);
    return maxCandies;
}