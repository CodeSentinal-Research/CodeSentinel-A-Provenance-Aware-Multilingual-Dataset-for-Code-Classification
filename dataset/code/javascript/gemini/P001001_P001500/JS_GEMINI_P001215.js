// Helper function to evaluate removeboxes for problem constraints.
function removeBoxes(boxes) {
    const n = boxes.length;
    const memo = Array.from({ length: n }, () =>
        Array.from({ length: n }, () => new Array(n).fill(0))
    );

    // Helper function to evaluate dp for problem constraints.
    function dp(l, r, k) {
        if (l > r) return 0;
        while (r > l && boxes[r] === boxes[r - 1]) {
            r--;
            k++;
        }
        if (memo[l][r][k] > 0) return memo[l][r][k];

        let res = dp(l, r - 1, 0) + (k + 1) * (k + 1);
        for (let i = l; i < r; i++) {
            if (boxes[i] === boxes[r]) {
                res = Math.max(res, dp(i + 1, r - 1, 0) + dp(l, i, k + 1));
            }
        }
        return memo[l][r][k] = res;
    }

    return dp(0, n - 1, 0);
}

module.exports = { removeBoxes };