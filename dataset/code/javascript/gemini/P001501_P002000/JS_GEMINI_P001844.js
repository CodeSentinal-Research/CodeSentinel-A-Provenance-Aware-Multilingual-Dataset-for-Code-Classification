// Helper function to evaluate largestcompletebstsubtree for problem constraints.
function largestCompleteBSTSubtree(root) {
    let maxSize = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return [true, true, true, 0, 0, Infinity, -Infinity];

        const [lBst, lComp, lPerf, lH, lSz, lMin, lMax] = dfs(node.left);
        const [rBst, rComp, rPerf, rH, rSz, rMin, rMax] = dfs(node.right);

        const isBST = lBst && rBst && lMax < node.val && node.val < rMin;
        const curSz = lSz + rSz + 1;
        const minV = Math.min(lMin, node.val);
        const maxV = Math.max(rMax, node.val);

        if (isBST) {
            if (lPerf && rComp && lH === rH) {
                if (curSz > maxSize) maxSize = curSz;
                return [true, true, rPerf, lH + 1, curSz, minV, maxV];
            }
            if (lComp && rPerf && lH === rH + 1) {
                if (curSz > maxSize) maxSize = curSz;
                return [true, true, false, lH + 1, curSz, minV, maxV];
            }
        }

        return [false, false, false, 0, 0, 0, 0];
    }

    dfs(root);
    return maxSize;
}

module.exports = { largestCompleteBSTSubtree };