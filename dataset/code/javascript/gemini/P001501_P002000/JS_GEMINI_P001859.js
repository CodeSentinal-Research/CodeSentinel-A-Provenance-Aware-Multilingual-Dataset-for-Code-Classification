// Helper function to evaluate largestperfectbstsubtree for problem constraints.
function largestPerfectBSTSubtree(root) {
    let maxSize = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return [true, true, 0, Infinity, -Infinity];

        const [lBst, lPerf, lH, lMin, lMax] = dfs(node.left);
        const [rBst, rPerf, rH, rMin, rMax] = dfs(node.right);

        const isBST = lBst && rBst && lMax < node.val && node.val < rMin;
        const minV = Math.min(lMin, node.val);
        const maxV = Math.max(rMax, node.val);

        if (isBST && lPerf && rPerf && lH === rH) {
            const curH = lH + 1;
            const size = (1 << curH) - 1;
            if (size > maxSize) maxSize = size;
            return [true, true, curH, minV, maxV];
        }

        return [false, false, 0, 0, 0];
    }

    dfs(root);
    return maxSize;
}

module.exports = { largestPerfectBSTSubtree };