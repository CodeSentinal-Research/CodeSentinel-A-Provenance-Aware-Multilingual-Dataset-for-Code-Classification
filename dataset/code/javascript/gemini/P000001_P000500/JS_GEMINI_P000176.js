function findMinDiff(a, n, m) {
    if (m === 0 || n === 0 || m > n) return 0;
    a.sort((x, y) => x - y);
    let minDiff = Infinity;
    for (let i = 0; i <= n - m; i++) {
        const diff = a[i + m - 1] - a[i];
        if (diff < minDiff) minDiff = diff;
    }
    return minDiff;
}

module.exports = { findMinDiff };