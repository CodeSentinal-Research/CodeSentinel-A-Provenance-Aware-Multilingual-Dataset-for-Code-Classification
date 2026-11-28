// Helper function to evaluate largestdeadendfreesubtree for problem constraints.
function largestDeadEndFreeSubtree(root) {
    let maxSize = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, low, high) {
        if (!node) return [true, 0];
        if (low === high) return [false, 0];

        const [lFree, lSz] = dfs(node.left, low, node.val - 1);
        const [rFree, rSz] = dfs(node.right, node.val + 1, high);

        if (lFree && rFree) {
            const curSize = lSz + rSz + 1;
            if (curSize > maxSize) maxSize = curSize;
            return [true, curSize];
        }

        return [false, 0];
    }

    dfs(root, 1, Infinity);
    return maxSize;
}

module.exports = { largestDeadEndFreeSubtree };