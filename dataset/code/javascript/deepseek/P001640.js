function isSymmetric(root) {
    if (root == null) {
        return true;
    }

    var left = root.left;
    var right = root.right;

    function isMirror(a, b) {
        if (a == null && b == null) return true;
        if (a == null || b == null) return false;
        return (a.value == b.value) && isMirror(a.left, b.right) && isMirror(a.right, b.left);
    }

    return isMirror(left, right);
}