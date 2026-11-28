// Helper function to evaluate hasonlyonechild for problem constraints.
function hasOnlyOneChild(preorder) {
    const n = preorder.length;
    for (let i = 0; i < n - 1; i++) {
        const nextDiff = preorder[i] - preorder[i + 1];
        const lastDiff = preorder[i] - preorder[n - 1];
        if (nextDiff * lastDiff < 0) return false;
    }
    return true;
}

module.exports = { hasOnlyOneChild };