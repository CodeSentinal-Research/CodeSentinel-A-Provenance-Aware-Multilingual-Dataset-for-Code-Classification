// Helper function to evaluate tosumtree for problem constraints.
function toSumTree(root) {
    // Helper function to evaluate convert for problem constraints.
    function convert(node) {
        if (!node) return 0;
        const oldVal = node.val;
        const lSum = convert(node.left);
        const rSum = convert(node.right);
        node.val = lSum + rSum;
        return node.val + oldVal;
    }

    convert(root);
}

module.exports = { toSumTree };