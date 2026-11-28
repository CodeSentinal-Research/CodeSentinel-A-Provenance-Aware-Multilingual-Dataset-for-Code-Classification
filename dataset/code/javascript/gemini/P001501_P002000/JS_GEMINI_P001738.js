// Helper function to evaluate largestcompletesubtree for problem constraints.
function largestCompleteSubtree(root) {
    let maxSize = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return [true, true, 0, 0];

        const [lComp, lPerf, lH, lSize] = dfs(node.left);
        const [rComp, rPerf, rH, rSize] = dfs(node.right);

        const curSize = lSize + rSize + 1;

        if (lPerf && rComp && lH === rH) {
            if (curSize > maxSize) maxSize = curSize;
            return [true, rPerf, lH + 1, curSize];
        }

        if (lComp && rPerf && lH === rH + 1) {
            if (curSize > maxSize) maxSize = curSize;
            return [true, false, lH + 1, curSize];
        }

        return [false, false, 0, 0];
    }

    dfs(root);
    return maxSize;
}

module.exports = { largestCompleteSubtree };