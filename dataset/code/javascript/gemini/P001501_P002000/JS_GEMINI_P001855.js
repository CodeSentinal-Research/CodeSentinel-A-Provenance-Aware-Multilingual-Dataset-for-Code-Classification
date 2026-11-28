// Helper function to evaluate mininsertionstocompletebst for problem constraints.
function minInsertionsToCompleteBST(root) {
    // Helper function to evaluate countnodes for problem constraints.
    function countNodes(node) {
        if (!node) return 0;
        return 1 + countNodes(node.left) + countNodes(node.right);
    }

    // Helper function to evaluate getheight for problem constraints.
    function getHeight(node) {
        if (!node) return 0;
        return 1 + Math.max(getHeight(node.left), getHeight(node.right));
    }

    const n = countNodes(root);
    const h = getHeight(root);
    const minNodes = 1 << (h - 1);
    return Math.max(0, minNodes - n);
}

module.exports = { minInsertionsToCompleteBST };