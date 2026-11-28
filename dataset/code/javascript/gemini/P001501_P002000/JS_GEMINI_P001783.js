// Helper function to evaluate findcentroid for problem constraints.
function findCentroid(root) {
    // Helper function to evaluate countnodes for problem constraints.
    function countNodes(node) {
        if (!node) return 0;
        return 1 + countNodes(node.left) + countNodes(node.right);
    }

    const totalNodes = countNodes(root);
    let centroid = -1;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return 0;
        const l = dfs(node.left);
        const r = dfs(node.right);
        const parentSize = totalNodes - (1 + l + r);

        if (l <= Math.floor(totalNodes / 2) && r <= Math.floor(totalNodes / 2) && parentSize <= Math.floor(totalNodes / 2)) {
            centroid = node.val;
        }

        return 1 + l + r;
    }

    dfs(root);
    return centroid;
}

module.exports = { findCentroid };