Here is a solution for the problem using JavaScript:

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
        let node = new Node(data);
        if (this.root === null) {
            this.root = node;
        }
        return node;
    }

    addNode(node, data) {
        if (node === null) {
            node = this.createNode(data);
        } else {
            if (data < node.data) {
                if (node.left === null) {
                    node.left = this.createNode(data);
                } else {
                    this.addNode(node.left, data);
                }
            } else {
                if (node.right === null) {
                    node.right = this.createNode(data);
                } else {
                    this.addNode(node.right, data);
                }
            }
        }
    }
}

function findAntiDiagonalSum(root) {
    let map = new Map();
    findAntiDiagonalHelper(root, 0, map);
    for (let [key, value] of map.entries()) {
        console.log(`Sum of nodes along anti-diagonal ${key}: ${value}`);
    }
}

function findAntiDiagonalHelper(node, diagonalSum, map) {
    if (node === null) return;
    diagonalSum += node.data;
    if (map.has(diagonalSum)) {
        map.set(diagonalSum, map.get(diagonalSum) + 1);
    } else {
        map.set(diagonalSum, 1);
    }
    findAntiDiagonalHelper(node.left, diagonalSum, map);
    findAntiDiagonalHelper(node.right, diagonalSum, map);
}

// Example usage
let binaryTree = new BinaryTree();
let input = [3, 1, 4, 3, 5, 4, 2, 4, 1, 3, 2, null, 5];

for (let data of input) {
    binaryTree.addNode(binaryTree.root, data);
}

findAntiDiagonalSum(binaryTree.root);

This code first creates a binary tree from the given input, then calls the `findAntiDiagonalSum` function to calculate and print the sum of the nodes along every anti-diagonal in the tree.

Please note that the input to this code is a list of integers. Each integer corresponds to a node's data, with the value of -1 indicating a null node. For example, the input `[3, 1, 4, 3, 5, 4, 2, 4, 1, 3, 2, -1, 5]` represents a binary tree with the following structure:

3
/ \
1   4
/ \ / \
3 5 4 2
/ \ / \
5 4 1 3