class TreeNode {
    constructor(val) { this.val = val; this.left = null; this.right = null; }
}


function insert(root, val) {
    if (!root) return new TreeNode(val);
    if (val < root.val) root.left = insert(root.left, val);
    else root.right = insert(root.right, val);
    return root;
}


function inorder(root, result = []) {
    if (!root) return result;
    inorder(root.left, result);
    result.push(root.val);
    inorder(root.right, result);
    return result;
}

module.exports = { TreeNode, insert, inorder };
