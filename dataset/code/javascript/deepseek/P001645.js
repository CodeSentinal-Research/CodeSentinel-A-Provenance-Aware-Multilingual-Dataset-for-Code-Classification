Here is the JavaScript code to solve the problem. We will use the concept of BFS to achieve the vertical order traversal. We use a map to store the nodes of each column number.

function Node(data) {
    this.data = data;
    this.left = this.right = null;
}

function levelOrder(root) {
    if (root === null) return;

    let map = new Map();
    let queue = [{node: root, column: 0}];

    while (queue.length) {
        let curr = queue.shift();

        if (!map.has(curr.column)) {
            map.set(curr.column, []);
        }

        map.get(curr.column).push(curr.node.data);

        if (curr.node.left) {
            queue.push({node: curr.node.left, column: curr.column - 1});
        }

        if (curr.node.right) {
            queue.push({node: curr.node.right, column: curr.column + 1});
        }
    }

    for (let arr of map.values()) {
        console.log(arr.join(" "));
    }
}

// Test the function with the following input
let root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);
root.right.left = new Node(6);
root.right.right = new Node(7);
levelOrder(root);

The `levelOrder` function uses a Breadth-First Search (BFS) approach to traverse the binary tree and print the nodes of each column from left to right. The `queue` stores each node and its column number, and the `map` stores each column number as a key and the list of nodes in that column as the value. The BFS algorithm ensures that the nodes in each column are visited in the order they were added to the queue.