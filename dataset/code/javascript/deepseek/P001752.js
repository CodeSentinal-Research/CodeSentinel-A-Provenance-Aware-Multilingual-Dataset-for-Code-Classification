const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputCount = parseInt(rl.question());
let lines = [];

rl.on('line', function(line) {
    lines.push(line);
    if (lines.length === inputCount) rl.close();
});

rl.on('close', function() {
    const tree = new Map();
    let maxNode = -1;

    function dfs(node, parent) {
        if (!tree.has(node)) {
            tree.set(node, new Set());
        }
        if (parent !== -1) {
            tree.get(node).add(parent);
            tree.get(parent).add(node);
        }

        let maxChild = -1;
        let childCount = 0;
        for (let child of tree.get(node)) {
            dfs(child, node);
            childCount++;
            if (tree.get(child).size > maxChild) {
                maxChild = tree.get(child).size;
            }
        }
        if (childCount > 0) {
            tree.get(node).add(childCount);
        }
    }

    for (let line of lines) {
        let [node, parent] = line.split(' ');
        dfs(parseInt(node), parseInt(parent));
    }

    for (let node of tree.keys()) {
        console.log(tree.get(node).size);
    }
});
This JavaScript code reads the input from the standard input and processes it. It uses a depth-first search approach to count the number of ancestors for each node. The input is read line by line, and each line is a pair of a node and its parent. The depth first search is performed starting from the root and moving to its children. The count of ancestors for each node is stored in a map.