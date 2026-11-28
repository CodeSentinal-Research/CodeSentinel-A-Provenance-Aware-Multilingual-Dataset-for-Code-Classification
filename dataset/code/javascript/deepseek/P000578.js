Here is the JavaScript solution for the problem using level order traversal to keep track of the nodes from left to right in each vertical column:

class Node {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

function topView(root) {
  if (!root) return [];

  let map = new Map();
  let queue = [{ node: root, column: 0 }];

  while (queue.length) {
    let current = queue.shift();
    let node = current.node;
    let column = current.column;

    if (!map.has(column)) {
      map.set(column, node.data);
    }

    if (node.left) {
      queue.push({ node: node.left, column: column - 1 });
    }

    if (node.right) {
      queue.push({ node: node.right, column: column + 1 });
    }
  }

  return Array.from(map.values()).sort((a, b) => a - b);
}

// Testing the function
let root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);
root.right.left = new Node(6);
root.right.right = new Node(7);
console.log(topView(root));

In this code, we use a Map to keep track of the data of nodes in each vertical column. The map stores the column number as the key and the data of the node as the value. In the while loop of the level order traversal, we first check if a node exists in the map, if it does then we update the value of the node else we set the value of the node. Then we add the left and right child of the current node to the queue.