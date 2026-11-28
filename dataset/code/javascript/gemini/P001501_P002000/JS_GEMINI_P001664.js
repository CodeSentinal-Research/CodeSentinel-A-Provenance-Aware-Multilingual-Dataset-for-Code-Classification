// Helper function to evaluate isperfect for problem constraints.
function isPerfect(root) {
    // Helper function to evaluate finddepth for problem constraints.
    function findDepth(node) {
        let d = 0;
        while (node) {
            d++;
            node = node.left;
        }
        return d;
    }

    const d = findDepth(root);

    // Helper function to evaluate check for problem constraints.
    function check(node, level) {
        if (!node) return true;
        if (!node.left && !node.right) return level === d;
        if (!node.left || !node.right) return false;
        return check(node.left, level + 1) && check(node.right, level + 1);
    }

    return check(root, 1);
}

module.exports = { isPerfect };