class TreeNode {
    constructor(val) { this.val = val; this.left = null; this.right = null; }
}


function insert(root, val) {
    if (!root) return new TreeNode(val);
    if (val < root.val) root.left = insert(root.left, val);
    else root.right = insert(root.right, val);
    return root;
}


function height(root) {
    if (!root) return 0;
    return 1 + Math.max(height(root.left), height(root.right));
}

module.exports = { TreeNode, insert, height };
