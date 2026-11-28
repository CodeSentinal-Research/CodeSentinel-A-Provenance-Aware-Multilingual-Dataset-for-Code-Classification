// Helper function to evaluate converttree for problem constraints.
function convertTree(root) {
    if (!root || (!root.left && !root.right)) return;

    const childSum = (root.left ? root.left.val : 0) + (root.right ? root.right.val : 0);
    if (childSum >= root.val) {
        root.val = childSum;
    } else {
        if (root.left) root.left.val = root.val;
        if (root.right) root.right.val = root.val;
    }

    convertTree(root.left);
    convertTree(root.right);

    const tot = (root.left ? root.left.val : 0) + (root.right ? root.right.val : 0);
    if (root.left || root.right) {
        root.val = tot;
    }
}

module.exports = { convertTree };