Here is the JavaScript code for the problem:

let fs = require('fs');
let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let depthMap = {};

function addNode(node, depth = 0) {
    if (depth in depthMap) {
        depthMap[depth].push(node);
    } else {
        depthMap[depth] = [node];
    }

    let leftNode = node.left;
    let rightNode = node.right;

    if (leftNode) {
        addNode(leftNode, depth + 1);
    }

    if (rightNode) {
        addNode(rightNode, depth + 1);
    }
}

rl.on('line', function(line) {
    if (line.trim() === '') return rl.close();

    let nodes = line.split(' ').map(Number);
    let root = {
        value: nodes[0],
        left: nodes[1] === -1 ? null : {value: nodes[1]},
        right: nodes[2] === -1 ? null : {value: nodes[2]}
    };

    addNode(root);
});

rl.on('close', function() {
    let maxDepth = Math.max(...Object.keys(depthMap));
    let sumOfDeepestNodes = depthMap[maxDepth].reduce((sum, node) => sum + node.value, 0);
    console.log(sumOfDeepestNodes);
    process.exit();
});
This code reads the tree from standard input in the format of binary tree. The tree is built and stored in a depthMap. The key in the depthMap is the depth of the node and the value is an array of nodes at that depth.
The sum of the deepest level nodes is calculated by summing up all the values of nodes at the maximum depth.