// Helper function to evaluate maxsumbst for problem constraints.
function maxSumBST(root) {
    let maxSum = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return [true, Infinity, -Infinity, 0];

        const [lBst, lMin, lMax, lSum] = dfs(node.left);
        const [rBst, rMin, rMax, rSum] = dfs(node.right);

        if (lBst && rBst && lMax < node.val && node.val < rMin) {
            const curSum = lSum + rSum + node.val;
            if (curSum > maxSum) maxSum = curSum;
            return [true, Math.min(lMin, node.val), Math.max(rMax, node.val), curSum];
        }

        return [false, 0, 0, 0];
    }

    dfs(root);
    return maxSum;
}

module.exports = { maxSumBST };