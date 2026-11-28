// Helper function to evaluate splitbst for problem constraints.
function splitBST(root, target) {
    if (!root) return [null, null];

    if (root.val <= target) {
        const [left, right] = splitBST(root.right, target);
        root.right = left;
        return [root, right];
    } else {
        const [left, right] = splitBST(root.left, target);
        root.left = right;
        return [left, root];
    }
}

module.exports = { splitBST };