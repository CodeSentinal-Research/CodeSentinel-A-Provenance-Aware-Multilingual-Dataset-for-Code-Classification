Here is the JavaScript code to solve the problem. This code uses a level order traversal approach where we use a queue data structure. We initialize a map to keep track of the bottom most node at every level.

class Node {
  constructor(data, left = null, right = null) {
    this.data = data;
    this.left = left;
    this.right = right;
  }
}

function bottomView(root) {
  if (root === null) {
    return;
  }

  let map = new Map();
  let queue = [root];

  while (queue.length > 0) {
    let node = queue.shift();
    let x = map.get(node.data);

    if (x === undefined || x[0] > node.data) {
      map.set(node.data, [node.data]);
    } else if (x !== undefined) {
      map.set(node.data, [...x, node.data]);
    }

    if (node.left !== null) {
      queue.push(node.left);
    }

    if (node.right !== null) {
      queue.push(node.right);
    }
  }

  for (let pair of map.values()) {
    console.log(pair[pair.length - 1]);
  }
}

// Testing
let root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);
root.right.left = new Node(6);
root.right.right = new Node(7);
bottomView(root);
In the above code, Node is a class representing a node in the binary tree. The 'bottomView' function takes the root of the binary tree as input and prints the bottom view of the tree. The 'map' variable is a Map object where each key is a node's data and the value is an array of its children's data. The node's data is stored in the array at the bottom of the array. The 'queue' is a queue that stores the nodes of the tree. The code runs a level order traversal of the tree, and for each node, it updates its data in the map and its children in the queue. At the end, it prints the data of the nodes from the map in the order they were processed.