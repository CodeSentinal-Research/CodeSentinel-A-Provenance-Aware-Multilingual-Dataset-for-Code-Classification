// Helper function to evaluate maxpathsum for problem constraints.
function maxPathSum(root) {
    let maxSum = -Infinity;

    // Helper function to evaluate gain for problem constraints.
    function gain(node) {
        if (!node) return 0;
        const leftGain = Math.max(0, gain(node.left));
        const rightGain = Math.max(0, gain(node.right));
        maxSum = Math.max(maxSum, node.val + leftGain + rightGain);
        return node.val + Math.max(leftGain, rightGain);
    }

    gain(root);
    return maxSum;
}

module.exports = { maxPathSum };