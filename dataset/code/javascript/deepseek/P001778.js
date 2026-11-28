Here is a JavaScript code for the given problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function solve(tree) {
    const stack = [];
    let count = 0;

    function dfs(node, direction) {
        if (!node) {
            return;
        }
        stack.push(node.value);
        if (direction === 'increasing') {
            if (stack[stack.length - 1] < node.value) {
                return;
            }
        } else {
            if (stack[stack.length - 1] > node.value) {
                return;
            }
        }
        if (!node.left && !node.right) {
            count++;
            return;
        }
        dfs(node.left, direction);
        dfs(node.right, direction);
        stack.pop();
    }

    dfs(tree, 'increasing');
    dfs(tree, 'decreasing');

    console.log(count);
}

let n = parseInt(rl.readline());

let tree = {
    value: parseInt(rl.readline()),
    left: null,
    right: null
};

let currentNode = tree;

for (let i = 1; i < n; i++) {
    let line = rl.readline().split(' ');
    currentNode.left = line[0] === 'null' ? null : {
        value: parseInt(line[0]),
        left: line[1] === 'null' ? null : {
            value: parseInt(line[1]),
            left: line[2] === 'null' ? null : {
                value: parseInt(line[2]),
                left: null,
                right: null
            },
            right: null
        },
        right: null
    };
    currentNode.right = line[0] === 'null' ? null : {
        value: parseInt(line[0]),
        left: line[1] === 'null' ? null : {
            value: parseInt(line[1]),
            left: line[2] === 'null' ? null : {
                value: parseInt(line[2]),
                left: null,
                right: null
            },
            right: null
        },
        right: null
    };
    currentNode = currentNode.left || currentNode.right;
}

solve(tree);
This code reads the input from the standard input, creates the binary tree and then solves the problem. The binary tree is created by reading lines from the standard input, and the tree is updated by moving to the left or right child of the current node.
The count of the root-to-leaf paths is updated when we find a leaf node. The count is stored in the variable `count` and printed to the standard output.