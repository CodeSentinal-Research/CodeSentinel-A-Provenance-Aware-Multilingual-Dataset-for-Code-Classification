Sure, here is the JavaScript code for the problem.

let nodes = {};
let index = 0;

class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

function insert(data, node) {
    if (data < node.data) {
        if (node.left) {
            insert(data, node.left);
        } else {
            node.left = new Node(data);
        }
    } else {
        if (node.right) {
            insert(data, node.right);
        } else {
            node.right = new Node(data);
        }
    }
}

function inOrder(node, k) {
    if (node) {
        inOrder(node.left, k);
        k.push(node.data);
        inOrder(node.right, k);
    }
}

function getRank(k, x) {
    let i = 0;
    while (i < k.length && k[i] < x) i++;
    return i;
}

function solve(input) {
    let root = new Node(input[0]);
    for (let i = 1; i < input.length; i++) {
        insert(input[i], root);
    }

    let k = [];
    inOrder(root, k);

    let x = parseInt(input[input.length - 1]);
    console.log(getRank(k, x));
}

process.stdin.resume();
process.stdin.on('data', (chunk) => {
    let input = chunk.toString().trim().split('\n');
    solve(input);
});
process.stdin.pause();

This code defines a Binary Search Tree (BST) with Node classes. It takes inputs in the format specified in the problem and calculates the rank of the key X in the BST.

The `insert` function is used to insert nodes into the BST.

The `inOrder` function is used to traverse the BST in ascending order and store the keys in an array.

The `getRank` function is used to find the rank of X in the BST.

The `solve` function is the main function that takes the input, creates the BST, and calculates the rank of X.

The input is read from stdin. When input is available, it is processed and the result is printed to stdout.