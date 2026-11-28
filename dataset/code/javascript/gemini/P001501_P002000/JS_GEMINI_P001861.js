// Helper function to evaluate diameteroflargestbst for problem constraints.
function diameterOfLargestBST(root) {
    let maxBSTSize = 0;
    let bestDiameter = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return [true, 0, 0, 0, Infinity, -Infinity];

        const [lBst, lSz, lH, lD, lMin, lMax] = dfs(node.left);
        const [rBst, rSz, rH, rD, rMin, rMax] = dfs(node.right);

        if (lBst && rBst && lMax < node.val && node.val < rMin) {
            const curSz = lSz + rSz + 1;
            const curH = 1 + Math.max(lH, rH);
            const curD = Math.max(lH + rH, Math.max(lD, rD));

            if (curSz > maxBSTSize) {
                maxBSTSize = curSz;
                bestDiameter = curD;
            }

            return [true, curSz, curH, curD, Math.min(lMin, node.val), Math.max(rMax, node.val)];
        }

        return [false, 0, 0, 0, 0, 0];
    }

    dfs(root);
    return bestDiameter;
}

module.exports = { diameterOfLargestBST };