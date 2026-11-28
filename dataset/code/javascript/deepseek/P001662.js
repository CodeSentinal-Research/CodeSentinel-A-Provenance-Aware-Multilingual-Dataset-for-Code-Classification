// Definition for a binary tree node.
function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val);
    this.left = (left===undefined ? null : left);
    this.right = (right===undefined ? null : right);
}

function isBalanced(root) {
    if (root === null) return true;

    let leftHeight = getHeight(root.left);
    let rightHeight = getHeight(root.right);

    if (Math.abs(leftHeight - rightHeight) > 1) return false;

    return isBalanced(root.left) && isBalanced(root.right);
}

function getHeight(node) {
    if (node === null) return 0;

    return Math.max(getHeight(node.left), getHeight(node.right)) + 1;
}

let root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(3);
root.left.left = new TreeNode(4);
root.left.right = new TreeNode(5);

console.log(isBalanced(root));  // Outputs: true

This code defines a TreeNode constructor, which represents a node in the binary tree. The `isBalanced` function checks whether a binary tree is balanced by comparing the heights of the left and right subtrees. The `getHeight` function calculates the height of a tree.

In the provided code, a binary tree with a root value of 1 is created. Then, 4 nodes (left and right children of the root) with values 2, 3, 4, and 5 are created. The `isBalanced` function is called on the root of the tree, which should return true since the tree is balanced.