class TreeNode {
    constructor(val) { this.val = val; this.left = null; this.right = null; }
}


function insert(root, val) {
    if (!root) return new TreeNode(val);
    if (val < root.val) root.left = insert(root.left, val);
    else root.right = insert(root.right, val);
    return root;
}


function preorder(root, result = []) {
    if (!root) return result;
    result.push(root.val);
    preorder(root.left, result);
    preorder(root.right, result);
    return result;
}

module.exports = { TreeNode, insert, preorder };
