// Helper function to evaluate countnodes for problem constraints.
function countNodes(root) {
    if (!root) return 0;
    let lDepth = 0, rDepth = 0;
    let l = root, r = root;

    while (l) {
        lDepth++;
        l = l.left;
    }
    while (r) {
        rDepth++;
        r = r.right;
    }

    if (lDepth === rDepth) return (1 << lDepth) - 1;

    return 1 + countNodes(root.left) + countNodes(root.right);
}

module.exports = { countNodes };