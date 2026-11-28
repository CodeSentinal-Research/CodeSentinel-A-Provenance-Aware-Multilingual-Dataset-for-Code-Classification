Here is the JavaScript code for the problem:

let N;
let tree = new Map();

function readInput() {
    N = parseInt(readline());
    for (let i = 1; i <= N; i++) {
        let inputLine = readline().split(' ');
        let node = parseInt(inputLine[0]);
        let left = parseInt(inputLine[1]);
        let right = parseInt(inputLine[2]);
        tree.set(node, {left: left, right: right});
    }
}

function findRightmostDeepestNode() {
    let maxDepth = -1;
    let maxNode = -1;
    for (let node of tree.keys()) {
        let depth = dfs(node, 0);
        if (depth > maxDepth) {
            maxDepth = depth;
            maxNode = node;
        }
    }
    console.log(maxNode);
}

function dfs(node, depth) {
    if (node === -1) {
        return -1;
    }
    let leftDepth = dfs(tree.get(node).left, depth + 1);
    let rightDepth = dfs(tree.get(node).right, depth + 1);
    return Math.max(leftDepth, rightDepth);
}

readInput();
findRightmostDeepestNode();

In this code, we first read the number of nodes from the input. Then we read the nodes and their children. The `findRightmostDeepestNode` function uses a depth-first search to find the node at the maximum depth. The `dfs` function recursively calculates the depth of the current node and its children. The node with the maximum depth is stored in the `maxNode` variable.