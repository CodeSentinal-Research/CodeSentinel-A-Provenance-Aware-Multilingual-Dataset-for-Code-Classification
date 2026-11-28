Here is a JavaScript solution for the given problem. In this solution, a tree is represented as an object where each node has a property named 'value' which holds the value of the node and a property 'children' which is an array of the children nodes.

class Node {
  constructor(value) {
    this.value = value;
    this.children = [];
  }
}

function checkLeafNodes(root, depth = 0) {
  if (!root) return true;

  if (!root.children.length) {
    return depth === 0;
  }

  for (let child of root.children) {
    if (!checkLeafNodes(child, depth + 1)) {
      return false;
    }
  }

  return true;
}

// You can test this code with an example binary tree like this:

let root = new Node(1);
root.children = [
  new Node(2),
  new Node(3),
  new Node(4),
  new Node(5)
];
root.children[0].children = [
  new Node(6),
  new Node(7)
];
root.children[0].children[0].children = [
  new Node(8),
  new Node(9)
];
root.children[2].children = [
  new Node(10)
];

console.log(checkLeafNodes(root) ? 'YES' : 'NO');

This code first defines a Node class with properties value and children. It then defines a function checkLeafNodes that takes a root node of a binary tree and an optional depth (default is 0 if not provided). The function checks if the root node is null or if the root node does not have any children. If both conditions are true, it returns true because all leaf nodes must be at the same level. If the root node is not null and has children, it checks each child node recursively. If any of the children nodes are not leaf nodes (i.e., they have children), it returns false. If all children nodes are leaf nodes, it returns true.