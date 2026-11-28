// Helper function to evaluate countsymmetricsubtrees for problem constraints.
function countSymmetricSubtrees(root) {
    let count = 0;

    // Helper function to evaluate ismirror for problem constraints.
    function isMirror(t1, t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2 || t1.val !== t2.val) return false;
        return isMirror(t1.left, t2.right) && isMirror(t1.right, t2.left);
    }

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return;
        if (isMirror(node.left, node.right)) count++;
        dfs(node.left);
        dfs(node.right);
    }

    dfs(root);
    return count;
}

module.exports = { countSymmetricSubtrees };