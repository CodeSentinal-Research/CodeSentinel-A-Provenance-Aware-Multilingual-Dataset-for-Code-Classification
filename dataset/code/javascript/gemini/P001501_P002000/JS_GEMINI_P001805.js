// Helper function to evaluate findmedian for problem constraints.
function findMedian(root) {
    const vals = [];

    // Helper function to evaluate inorder for problem constraints.
    function inorder(node) {
        if (!node) return;
        inorder(node.left);
        vals.push(node.val);
        inorder(node.right);
    }

    inorder(root);
    const n = vals.length;
    if (n === 0) return 0;
    if (n % 2 === 1) return vals[Math.floor(n / 2)];
    return (vals[n / 2 - 1] + vals[n / 2]) / 2;
}

module.exports = { findMedian };