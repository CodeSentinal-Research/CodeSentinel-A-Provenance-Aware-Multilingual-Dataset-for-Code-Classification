// Helper function to evaluate largestperfectsubtree for problem constraints.
function largestPerfectSubtree(root) {
    let maxSize = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return 0;
        const l = dfs(node.left);
        const r = dfs(node.right);

        if (l !== -1 && r !== -1 && l === r) {
            const depth = l + 1;
            const size = (1 << depth) - 1;
            if (size > maxSize) maxSize = size;
            return depth;
        }

        return -1;
    }

    dfs(root);
    return maxSize;
}

module.exports = { largestPerfectSubtree };