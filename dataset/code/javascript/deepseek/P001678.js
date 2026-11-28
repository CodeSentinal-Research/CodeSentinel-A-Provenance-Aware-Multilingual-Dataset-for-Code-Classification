Here is the JavaScript code for the given problem:

let map = new Map();
let parent = null;
let depth = 0;
let nodeValue = null;

function dfs(node, parentNode, depthVal) {
    if (node === null) return;
    map.set(node.value, node);
    parent = parentNode;
    depth = depthVal;
    dfs(node.left, node.value, depthVal + 1);
    dfs(node.right, node.value, depthVal + 1);
}

function checkCousins(nodeValue1, nodeValue2) {
    let node1 = map.get(nodeValue1);
    let node2 = map.get(nodeValue2);

    if (node1.parent !== parent && node2.parent !== parent) {
        return node1.parent === node2.parent ? 'NO' : 'YES';
    }

    return 'NO';
}

class Node {
    constructor(value, left = null, right = null) {
        this.value = value;
        this.left = left;
        this.right = right;
        this.parent = parent;
    }
}

// input
const N = parseInt(readline());
const nodes = new Array(N + 2).fill(null).map(() => readline().split(' ').map(Number));
const nodeValue1 = nodes[N][0];
const nodeValue2 = nodes[N][1];

const root = new Node(nodes[0][0]);
const tree = new Map();
tree.set(nodes[0][0], root);
for (let i = 1; i < N; i++) {
    const parent = nodes[i][0];
    const child = nodes[i][1];
    const node = new Node(child);
    tree.set(child, node);
    if (parent === nodes[0][0]) {
        root.left = node;
    } else {
        root.right = node;
    }
}

dfs(root);

console.log(checkCousins(nodeValue1, nodeValue2));

This script first reads the input and constructs the binary tree. Then, it performs a depth-first search (DFS) to find the nodes and their parent nodes. The checkCousins function then compares the parent nodes of the two nodes. If they are not the same and they are not in the same tree level (depth), then they are cousins.