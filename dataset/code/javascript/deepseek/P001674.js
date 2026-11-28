Here is the JavaScript code using Depth-First Search (DFS) to solve this problem.

class TreeNode {
  constructor(x) {
    this.val = x;
    this.left = null;
    this.right = null;
  }
}

function solve(root) {
  let max_val = -Infinity;
  let res = [];

  function dfs(node, depth) {
    if (node == null) {
      return;
    }

    if (depth > max_val) {
      max_val = depth;
      res.push(node.val);
    }

    dfs(node.right, depth + 1);
    dfs(node.left, depth + 1);
  }

  dfs(root, 0);

  return res;
}

The function `solve` takes a root node of a binary tree and returns an array of the right-view nodes. It uses a helper function `dfs` to perform the depth-first search. This function takes a node and a depth as input, and pushes the node's value to the result array if the depth is greater than the maximum depth seen so far. The function then recursively calls itself for the node's right and left children, incrementing the depth by 1.