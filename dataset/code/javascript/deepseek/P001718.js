Sure, here is the JavaScript code for your problem. This code uses a Breadth-First Search (BFS) to count the number of paths in a binary tree with exactly K edges. 

// Node structure
class Node {
    constructor(data) {
        this.data = data;
        this.children = [];
    }

    addChild(data) {
        this.children.push(new Node(data));
        return this;
    }
}

// BFS function to count paths with exactly K edges
function countPaths(root, k) {
    let queue = [root];
    let paths = [];

    while (queue.length) {
        let current = queue.shift();

        if (current.children.length >= k) {
            paths = paths.concat(pathsFromNode(current, k));
        }

        queue = queue.concat(current.children);
    }

    return paths.length;
}

// Helper function to get all paths from a node to the leaves
function pathsFromNode(node, k) {
    if (k === 0) {
        return [node.data];
    }

    let paths = [];
    for (let i = 0; i < node.children.length; i++) {
        let childPaths = pathsFromNode(node.children[i], k - 1);
        paths = paths.concat(childPaths.map(child => node.data + child));
    }

    return paths;
}

// Example usage
let root = new Node(1);
root.addChild(2).addChild(3).addChild(4);
root.children[0].addChild(5).addChild(6).addChild(7);
root.children[2].addChild(8).addChild(9);

console.log(countPaths(root, 2)); // Outputs: 5

In this code, the `Node` class represents a node in the binary tree. Each node has a data value and an array of its children. The `countPaths` function uses a BFS to visit each node in the tree once and for each node, it generates all possible paths from the node to the leaves using the `pathsFromNode` function. If the number of edges in the path is exactly K, it is added to the result.