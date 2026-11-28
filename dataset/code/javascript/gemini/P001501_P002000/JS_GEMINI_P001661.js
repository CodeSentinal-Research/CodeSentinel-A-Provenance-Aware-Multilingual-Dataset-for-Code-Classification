// Helper function to evaluate isfoldable for problem constraints.
function isFoldable(root) {
    if (!root) return true;

    // Helper function to evaluate isfoldablemirror for problem constraints.
    function isFoldableMirror(t1, t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return isFoldableMirror(t1.left, t2.right) && isFoldableMirror(t1.right, t2.left);
    }

    return isFoldableMirror(root.left, root.right);
}

module.exports = { isFoldable };