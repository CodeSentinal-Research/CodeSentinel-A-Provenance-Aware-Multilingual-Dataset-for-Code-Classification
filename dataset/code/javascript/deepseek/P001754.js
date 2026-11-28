Sure, here is a JavaScript solution for the problem using Breadth First Search (BFS) for finding the leftmost node at the maximum depth. 

class TreeNode {
    constructor(x) {
        this.val = x;
        this.left = null;
        this.right = null;
    }
}

let input = require('fs').readFileSync('stdin', 'utf8');
let N = Number(input.split('\n')[0]);
let tree = new Map();
for (let i = 1; i <= N; ++i) {
    let [node, left, right] = input.split('\n')[i].split(' ');
    tree.set(node, new TreeNode(node));
    if (left !== 'null') tree.get(node).left = tree.get(left);
    if (right !== 'null') tree.get(node).right = tree.get(right);
}

let maxDepth = -Infinity;
let minNode = null;
let bfs = (node, depth) => {
    if (depth > maxDepth) {
        maxDepth = depth;
        minNode = node;
    } else if (depth === maxDepth && node.val < minNode.val) {
        minNode = node;
    }
    if (node.left) bfs(node.left, depth + 1);
    if (node.right) bfs(node.right, depth + 1);
}
bfs(tree.get(Object.keys(tree)[0] , 0);

console.log(minNode.val);

This solution uses BFS to traverse through the tree. It keeps track of the maximum depth and the node with the minimum value at that depth. If it finds a node with a deeper depth, it updates the minimum node. If it finds a node with the same depth but a smaller value, it updates the minimum node.

Please note that you need to provide input in the format specified in the problem and that the input is handled correctly.