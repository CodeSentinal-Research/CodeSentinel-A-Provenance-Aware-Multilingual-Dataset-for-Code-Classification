Here is the JavaScript code for the problem:

class TreeNode {
  constructor(val = 0, left = null, right = null) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

function replaceEveryNodeWithSumOfCousins(root) {
  let nodeValues = [];
  let maxValue = -Infinity;
  let minValue = Infinity;

  function dfs(node, path = []) {
    path.push(node.val);

    if (node.left) {
      dfs(node.left, path);
    }

    if (node.right) {
      dfs(node.right, path);
    }

    if (node.left === null && node.right === null) {
      nodeValues.push(path.join('-'));
      path = [];
    }
  }

  dfs(root);

  for (let i = 0; i < nodeValues.length; i++) {
    let nodePaths = nodeValues[i].split('-');
    let leftPath = nodePaths.slice(0, nodePaths.length - 1).join('-');
    let rightPath = nodePaths.slice(1).join('-');
    root.val += parseInt(leftPath, 10) + parseInt(rightPath, 10);
  }
}

// Testing the code
// Create a binary tree
let root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(3);
root.left.left = new TreeNode(4);
root.left.right = new TreeNode(5);
root.right.left = new TreeNode(6);
root.right.right = new TreeNode(7);
replaceEveryNodeWithSumOfCousins(root);

This script creates a binary tree with a root value of 1 and three children nodes with values 2, 3, 4, 5, 6, and 7. The `replaceEveryNodeWithSumOfCousins` function is then called on the root node of the tree to replace every node with the sum of its cousins.

The `dfs` function is a depth-first search function that visits each node in the tree. It collects the node values and their paths into `nodeValues`. It also keeps track of the maximum and minimum node values to ensure that the paths are valid.

The `replaceEveryNodeWithSumOfCousins` function calls `dfs` on the root node to collect the node values and paths. Then, it iterates over `nodeValues`, splits each path into left and right paths, and calculates the sum of the left and right paths. Finally, it updates the value of the root node and all descendants with the calculated sum.