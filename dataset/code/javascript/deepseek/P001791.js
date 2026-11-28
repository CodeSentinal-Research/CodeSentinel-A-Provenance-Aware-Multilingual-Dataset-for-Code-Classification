Here is the JavaScript code for finding the maximum value in a Binary Search Tree:

function Node(data) {
    this.data = data;
    this.left = null;
    this.right = null;
}

function Insert(root, node) {
    if (root === null) {
        root = node;
    } else if (node.data < root.data) {
        if (root.left === null) {
            root.left = node;
        } else {
            Insert(root.left, node);
        }
    } else {
        if (root.right === null) {
            root.right = node;
        } else {
            Insert(root.right, node);
        }
    }
}

function maxValue(node) {
    if (node === null) {
        return -1;
    } else if (node.right === null) {
        return node.data;
    } else {
        return maxValue(node.right);
    }
}

The `Insert` function is used to insert new nodes into the Binary Search Tree. It takes the root of the tree and a new node as parameters, and inserts the new node at the appropriate location in the tree, maintaining the BST property.

The `maxValue` function is used to find the maximum value in the Binary Search Tree. It takes the root of the tree as a parameter, and returns the maximum value of the tree by recursively traversing the right subtree. If the right subtree is empty, it returns the root's data.