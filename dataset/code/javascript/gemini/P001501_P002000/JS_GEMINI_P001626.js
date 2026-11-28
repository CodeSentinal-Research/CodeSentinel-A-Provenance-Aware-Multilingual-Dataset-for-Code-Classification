// Helper function to evaluate maxsidelength for problem constraints.
function maxSideLength(mat, threshold) {
    const m = mat.length, n = mat[0].length;
    const p = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            p[i + 1][j + 1] = mat[i][j] + p[i][j + 1] + p[i + 1][j] - p[i][j];
        }
    }

    let lo = 0, hi = Math.min(m, n);
    let ans = 0;

    while (lo <= hi) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor((lo + hi) / 2);
        if (mid === 0) { lo = 1; continue; }
        let found = false;

        for (let i = 0; i <= m - mid; i++) {
            for (let j = 0; j <= n - mid; j++) {
                const sum = p[i + mid][j + mid] - p[i][j + mid] - p[i + mid][j] + p[i][j];
                if (sum <= threshold) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (found) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

module.exports = { maxSideLength };