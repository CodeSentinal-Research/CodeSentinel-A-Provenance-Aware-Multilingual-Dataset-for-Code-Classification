function findPair(root, sum) {
    let set = new Set();
    let nodes = [];
    function traverse(node) {
        if (!node) return false;
        if (set.has(node.val)) return true;
        set.add(sum - node.val);
        return traverse(node.left) || traverse(node.right);
    }
    traverse(root);
    return nodes.length > 0;
}