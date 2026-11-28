Here's a JavaScript solution using a level order traversal approach:

class Node {
  constructor(val) {
    this.val = val;
    this.left = null;
    this.right = null;
  }
}

function solve(root) {
  if (root === null) {
    console.log("Empty Tree");
    return;
  }

  let queue = [root];
  let sum = root.val;
  let count = 1;
  while (queue.length !== 0) {
    let currentNode = queue.shift();
    if (currentNode.left !== null) {
      queue.push(currentNode.left);
      sum += currentNode.left.val;
      count++;
    }
    if (currentNode.right !== null) {
      queue.push(currentNode.right);
      sum += currentNode.right.val;
      count++;
    }

    if (queue.length === 0) {
      console.log(sum / count);
      sum = 0;
      count = 0;
      queue = [root];
    }
  }
}

This code creates a binary tree from the given input. It uses a level order traversal approach to visit each level of the tree. On each level, it calculates the sum of the node values and the count of nodes at that level. Then it prints the average at that level.

Please note that this code assumes that the input is a binary tree represented as a root node. If your input is different, you might need to adjust the code accordingly.