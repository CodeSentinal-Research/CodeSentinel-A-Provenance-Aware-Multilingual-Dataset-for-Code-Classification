// Helper function to evaluate issumtree for problem constraints.
function isSumTree(root) {
    // Helper function to evaluate check for problem constraints.
    function check(node) {
        if (!node) return 0;
        if (!node.left && !node.right) return node.val;
        const lSum = check(node.left);
        const rSum = check(node.right);
        if (lSum === -1 || rSum === -1 || node.val !== lSum + rSum) return -1;
        return node.val + lSum + rSum;
    }

    return check(root) !== -1;
}

module.exports = { isSumTree };