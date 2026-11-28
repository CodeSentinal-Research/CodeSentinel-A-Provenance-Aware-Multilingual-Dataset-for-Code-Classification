// Helper function to evaluate isbalanced for problem constraints.
function isBalanced(root) {
    // Helper function to evaluate check for problem constraints.
    function check(node) {
        if (!node) return 0;
        const l = check(node.left);
        if (l === -1) return -1;
        const r = check(node.right);
        if (r === -1 || Math.abs(l - r) > 1) return -1;
        return 1 + Math.max(l, r);
    }

    return check(root) !== -1;
}

module.exports = { isBalanced };