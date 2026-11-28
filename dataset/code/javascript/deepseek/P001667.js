Here is a JavaScript solution for the problem:

const fs = require('fs');
process.stdin.resume();
process.stdin.setEncoding('ascii');

let input = "";
process.stdin.on("data", chunk => {
    input += chunk;
});

process.stdin.on("end", _ => {
    process.stdout.write(input);
});

fs.readFileSync(0, 'utf8').split('\n').map(ign => {});

// Node class
class Node {
    constructor(data, left = null, right = null) {
        this.data = data;
        this.left = left;
        this.right = right;
    }
}

// Binary Tree
class BinaryTree {
    constructor(root = null) {
        this.root = root;
    }

    // Method to calculate maximum difference
    maxDiff(node1, node2, max, min) {
        if (!node1 && !node2) {
            return;
        }
        if (!node1) {
            max = Math.max(max, node2.data);
            min = Math.min(min, node2.data);
            return this.maxDiff(node1.left, node2.left, max, min);
        } else if (!node2) {
            max = Math.max(max, node1.data);
            min = Math.min(min, node1.data);
            return this.maxDiff(node1.right, node2.right, max, min);
        } else {
            max = Math.max(max, node1.data, node2.data);
            min = Math.min(min, node1.data, node2.data);
            return this.maxDiff(node1.left, node2.left, max, min);
        }
    }
}

// Solution
let n = parseInt(fs.readline());
let arr = fs.readline().toString().split(' ').map(Number);

let nodes = [];
for (let i = 0; i < n; i++) {
    nodes[i] = new Node(arr[i]);
}

let tree = new BinaryTree(nodes[0]);

let max = -Infinity;
let min = Infinity;
tree.maxDiff(tree.root, tree.root, max, min);

console.log(max - min);

This solution reads the input from the standard input in a buffer, then processes the input line by line. It uses a binary tree and a helper function `maxDiff` to calculate the maximum difference between a node's value and any of its ancestors.