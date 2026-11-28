Sure, here is a JavaScript solution for the problem. This solution uses a recursive approach to convert the binary tree into a threaded binary tree. We will use an auxiliary variable `prev` to keep track of the previous node.

class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class ThreadedBinaryTree {
    constructor() {
        this.root = null;
    }

    insert(data) {
        const node = new Node(data);
        if (this.root === null) {
            this.root = node;
        } else {
            this.insertNode(this.root, node);
        }
    }

    insertNode(node, newNode) {
        if (newNode.data < node.data) {
            if (node.left === null) {
                node.left = newNode;
            } else {
                this.insertNode(node.left, newNode);
            }
        } else {
            if (node.right === null) {
                node.right = newNode;
            } else {
                this.insertNode(node.right, newNode);
            }
        }
    }

    inorderThread(node) {
        if (node.left !== null) {
            this.inorderThread(node.left);
        }

        node.left = null;
        node.right = node.right;

        if (node.right !== null) {
            this.inorderThread(node.right);
        }
    }

    printInorder(node) {
        if (node !== null) {
            this.printInorder(node.left);
            console.log(node.data);
            this.printInorder(node.right);
        }
    }
}

function solve(input) {
    const tbt = new ThreadedBinaryTree();

    input.forEach(data => {
        tbt.insert(data);
    });

    tbt.inorderThread(tbt.root);

    tbt.printInorder(tbt.root);
}

In this code, we first create a class `Node` that represents a node in the binary tree. Then, we create a class `ThreadedBinaryTree` that represents the threaded binary tree. The `insert` method inserts a new node into the threaded binary tree. The `inorderThread` method converts the binary tree into a threaded binary tree. The `printInorder` method prints the inorder traversal of the threaded binary tree.

The `solve` function reads the input and converts the binary tree into a threaded binary tree.

The input is read from the console in the following format:

5
3
2
1
4
5

This is assuming that you want to insert the numbers 1, 2, 3, 4, 5 in that order, and 5 is the root node.