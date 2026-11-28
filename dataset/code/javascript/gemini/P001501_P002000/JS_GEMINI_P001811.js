// Helper function to evaluate largestbstsubtree for problem constraints.
function largestBSTSubtree(root) {
    let maxSize = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return [true, 0, Infinity, -Infinity];

        const [lBst, lSize, lMin, lMax] = dfs(node.left);
        const [rBst, rSize, rMin, rMax] = dfs(node.right);

        if (lBst && rBst && lMax < node.val && node.val < rMin) {
            const curSize = lSize + rSize + 1;
            if (curSize > maxSize) maxSize = curSize;
            return [true, curSize, Math.min(lMin, node.val), Math.max(rMax, node.val)];
        }

        return [false, 0, 0, 0];
    }

    dfs(root);
    return maxSize;
}

module.exports = { largestBSTSubtree };