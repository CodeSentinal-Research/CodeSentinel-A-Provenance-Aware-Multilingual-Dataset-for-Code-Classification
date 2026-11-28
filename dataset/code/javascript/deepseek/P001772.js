Here is the JavaScript code to solve the problem:

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

    createNode(data) {
        return new Node(data);
    }

    insertNode(node, data) {
        if (!node) {
            return this.createNode(data);
        } else if (node.data > data) {
            node.left = this.insertNode(node.left, data);
        } else {
            node.right = this.insertNode(node.right, data);
        }
        return node;
    }

    add(arr) {
        this.root = this.insertNode(this.root, arr[0]);
        for (let i = 1; i < arr.length; i++) {
            this.insertNode(this.root, arr[i]);
        }
    }

    getDiagonalSum(node, m) {
        if (!node) {
            return 0;
        }
        if (m == -1) {
            m = 0;
        }
        m++;
        return (node.data +
            this.getDiagonalSum(node.right, m) +
            this.getDiagonalSum(node.left, m)) / 2;
    }

    solve(arr) {
        this.add(arr);
        let diagonalSums = [];
        for (let i = 0; i < arr.length; i++) {
            diagonalSums.push(
                this.getDiagonalSum(this.root, -1)
            );
        }
        return diagonalSums;
    }
}

// Input handling
const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

const N = parseInt(rl.question(''));
const arr = rl.readline().split(' ');

const BT = new BinaryTree();

console.log(BT.solve(arr));

In this code, we create a BinaryTree class with methods to add nodes to the binary tree and calculate the diagonal sums. The solve method calls the add method to add the nodes from the input array to the binary tree, and then it calls the getDiagonalSum method to calculate the diagonal sums of the binary tree. 

Please note that this code assumes that the input is a valid binary tree, i.e., it is a sequence of node values, where each node value is followed by two node values (representing the left and right children of the node) if it exists.