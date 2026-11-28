// Helper function to evaluate issubtree for problem constraints.
function isSubtree(root, subRoot) {
    if (!root) return false;
    if (isSame(root, subRoot)) return true;
    return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
}

// Helper function to evaluate issame for problem constraints.
function isSame(p, q) {
    if (!p && !q) return true;
    if (!p || !q || p.val !== q.val) return false;
    return isSame(p.left, q.left) && isSame(p.right, q.right);
}

module.exports = { isSubtree };