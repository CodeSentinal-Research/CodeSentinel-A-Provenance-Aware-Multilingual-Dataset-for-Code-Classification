// Helper function to evaluate largestunivaluesubtree for problem constraints.
function largestUnivalueSubtree(root) {
    let maxSize = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return [true, 0];
        const [lUnival, lSize] = dfs(node.left);
        const [rUnival, rSize] = dfs(node.right);

        if (lUnival && rUnival) {
            if ((!node.left || node.left.val === node.val) && (!node.right || node.right.val === node.val)) {
                const curSize = lSize + rSize + 1;
                if (curSize > maxSize) maxSize = curSize;
                return [true, curSize];
            }
        }
        return [false, 0];
    }

    dfs(root);
    return maxSize;
}

module.exports = { largestUnivalueSubtree };