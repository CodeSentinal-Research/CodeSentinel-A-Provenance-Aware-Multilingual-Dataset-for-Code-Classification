// Helper function to evaluate issubtree for problem constraints.
function isSubtree(root, subRoot) {
    // Helper function to evaluate issame for problem constraints.
    function isSame(t1, t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2 || t1.val !== t2.val) return false;
        return isSame(t1.left, t2.left) && isSame(t1.right, t2.right);
    }

    if (!root) return !subRoot;
    if (isSame(root, subRoot)) return true;
    return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
}

module.exports = { isSubtree };