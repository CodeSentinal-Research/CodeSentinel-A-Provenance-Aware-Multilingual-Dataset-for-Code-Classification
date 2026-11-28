class TreeNode {
    constructor(val) { this.val = val; this.left = null; this.right = null; }
}


function insert(root, val) {
    if (!root) return new TreeNode(val);
    if (val < root.val) root.left = insert(root.left, val);
    else if (val > root.val) root.right = insert(root.right, val);
    return root;
}


function search(root, key) {
    if (!root || root.val === key) return root;
    if (key < root.val) return search(root.left, key);
    return search(root.right, key);
}


function inorder(root, result = []) {
    if (!root) return result;
    inorder(root.left, result);
    result.push(root.val);
    inorder(root.right, result);
    return result;
}

module.exports = { TreeNode, insert, search, inorder };
