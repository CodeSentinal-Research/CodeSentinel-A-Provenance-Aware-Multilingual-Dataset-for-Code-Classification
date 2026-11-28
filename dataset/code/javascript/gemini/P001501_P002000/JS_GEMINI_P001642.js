// Helper function to evaluate diameterofbinarytree for problem constraints.
function diameterOfBinaryTree(root) {
    let ans = 0;

    // Helper function to evaluate depth for problem constraints.
    function depth(node) {
        if (!node) return 0;
        const l = depth(node.left);
        const r = depth(node.right);
        ans = Math.max(ans, l + r);
        return 1 + Math.max(l, r);
    }

    depth(root);
    return ans;
}

module.exports = { diameterOfBinaryTree };