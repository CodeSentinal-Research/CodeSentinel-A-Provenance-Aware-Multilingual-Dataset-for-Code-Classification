Sure, here is a JavaScript solution that follows the problem's requirements.

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
        this.nodes = [];
    }

    addNode(data) {
        const newNode = new Node(data);
        if (this.root === null) {
            this.root = newNode;
        } else {
            this.insertNode(this.root, newNode);
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

    removeLeaves() {
        this.nodes = [];
        if (this.root === null) {
            return;
        }
        this.removeLeavesRecursive(this.root);
    }

    removeLeavesRecursive(node) {
        if (node.left && node.right === null) {
            this.nodes.push(node.data);
            node.left = null;
            node.right = null;
            return;
        }
        if (node.left && node.left.left === null && node.left.right === null) {
            this.nodes.push(node.left.data);
            node.left = null;
            return;
        }
        if (node.right && node.right.left === null && node.right.right === null) {
            this.nodes.push(node.right.data);
            node.right = null;
            return;
        }
        if (node.left) {
            this.removeLeavesRecursive(node.left);
        }
        if (node.right) {
            this.removeLeavesRecursive(node.right);
        }
    }
}

let tree = new BinaryTree();

const fs = require('fs');

fs.readFileSync('input.txt', 'utf8').split('\n').forEach((line) => {
    if (line !== '') {
        tree.addNode(parseInt(line));
    }
});

while (tree.root) {
    tree.removeLeaves();
    console.log(tree.nodes.join(' '));
    tree.nodes = [];
}

This code first defines a `Node` class to represent each node in the binary tree. Then, it defines a `BinaryTree` class to handle the binary tree operations. 

In the `BinaryTree` class, `addNode` function is used to add a new node to the binary tree. `insertNode` function is a recursive function that inserts a new node into the binary tree. 

`removeLeaves` function is used to remove all leaf nodes in a binary tree. It uses the `removeLeavesRecursive` function to remove the leaf nodes. 

The code then reads input from an input file (input.txt), adds each node to the binary tree, removes all leaf nodes and reports the nodes removed in each round.