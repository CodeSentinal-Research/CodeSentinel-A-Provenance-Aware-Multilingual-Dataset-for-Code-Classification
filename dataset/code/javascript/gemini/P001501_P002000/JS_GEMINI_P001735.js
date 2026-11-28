// Helper function to evaluate issymmetric for problem constraints.
function isSymmetric(root) {
    // Helper function to evaluate ismirror for problem constraints.
    function isMirror(t1, t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2 || t1.val !== t2.val) return false;
        return isMirror(t1.left, t2.right) && isMirror(t1.right, t2.left);
    }

    return isMirror(root, root);
}

module.exports = { isSymmetric };