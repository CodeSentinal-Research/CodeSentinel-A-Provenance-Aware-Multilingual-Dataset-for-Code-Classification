Here is a JavaScript solution using Depth-First Search (DFS) approach:

// Node structure
class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

// Construct the tree
let root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);
root.right.left = new Node(6);
root.right.right = new Node(7);

let target = 3;
let k = 2;

function findNodes(root, target, k) {
    let parent = { [target]: null };
    let distance = { [target]: 0 };
    let queue = [[root, null]];

    while (queue.length > 0) {
        let current = queue.pop();
        if (current[0].left) {
            parent[current[0].left.data] = current[0].data;
            distance[current[0].left.data] = current[1] + 1;
            queue.push([current[0].left, current[1] + 1]);
        }
        if (current[0].right) {
            parent[current[0].right.data] = current[0].data;
            distance[current[0].right.data] = current[1] + 1;
            queue.push([current[0].right, current[1] + 1]);
        }
    }

    for (let node in parent) {
        if (distance[node] === k) {
            console.log(node);
        }
    }
}

findNodes(root, target, k);

In this code, we first create a binary tree with 7 nodes. Then we find all nodes at distance K from a target node and print them.

In the findNodes function, we use a Breadth-First Search (BFS) approach. We use a queue and two dictionaries to record parent node and distance of each node. Starting from the root node, we move to its children and add them to the queue and the dictionaries. When the queue is empty, we find all nodes at distance K.

Please note that this is a simple solution and does not handle the input part. You will need to provide input for the number of nodes and each node's data. Also, the input format should be as described in the problem.