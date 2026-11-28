Here is a JavaScript solution for the given problem. 

First, we need to define a Node object and Binary Tree object. Then, we can create a function to print the boundary traversal of a binary tree.

class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class BinaryTree {
    constructor() {
        this.root = null;
    }

    printBoundary(root) {
        if (root == null) {
            return;
        }

        // Print top boundary
        console.log(root.data);

        // Print left boundary
        this.printLeftBoundary(root.left);

        // Print leaves
        this.printLeaves(root.left);
        this.printLeaves(root.right);

        // Print right boundary
        this.printRightBoundary(root.right);
    }

    printLeftBoundary(node) {
        if (node == null) {
            return;
        }

        console.log(node.data);
        this.printLeftBoundary(node.left);
    }

    printRightBoundary(node) {
        if (node == null) {
            return;
        }

        this.printRightBoundary(node.right);
        console.log(node.data);
    }

    printLeaves(node) {
        if (node == null) {
            return;
        }

        if (node.left == null && node.right == null) {
            console.log(node.data);
        }

        this.printLeaves(node.left);
        this.printLeaves(node.right);
    }
}

// Usage
let tree = new BinaryTree();
tree.root = new Node(1);
tree.root.left = new Node(2);
tree.root.right = new Node(3);
tree.root.left.left = new Node(4);
tree.root.left.right = new Node(5);
tree.root.right.left = new Node(6);
tree.root.right.right = new Node(7);

tree.printBoundary(tree.root);

In the above code, the printBoundary method is implemented to print the boundary traversal of a binary tree. It is called recursively for all the left, right, and leaves of a node. The left boundary is printed for the root and leaves while the right boundary is printed for the leaves and root.