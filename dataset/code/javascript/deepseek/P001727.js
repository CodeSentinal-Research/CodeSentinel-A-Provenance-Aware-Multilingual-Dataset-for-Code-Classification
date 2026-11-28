Here is the JavaScript code for your problem:

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

    add(data) {
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

    printPath(node) {
        if (node === null) {
            return;
        }

        let str = '';
        if (node.left) {
            str += node.left.data + ' ';
            this.printPath(node.left);
        }

        if (node.right) {
            str += node.right.data + ' ';
            this.printPath(node.right);
        }

        console.log(str.trim());
    }

    printAllPaths() {
        if (this.root === null) {
            return;
        }

        this.printPath(this.root);
    }
}

let tree = new BinaryTree();
let input = require('fs').readFileSync('input.txt', 'utf8');
input = input.split('\n');

input.shift(); // removing first line

for (let i of input) {
    tree.add(parseInt(i));
}

tree.printAllPaths();

In this code, we first define a Node class and a BinaryTree class. The Node class is used to create a new node in the binary tree. The BinaryTree class is used to add new nodes to the binary tree, and print all the distinct root-to-leaf paths.

The input from the file 'input.txt' is read and parsed. Each line is parsed as an integer and added to the binary tree. The binary tree is then traversed to print all the root-to-leaf paths.