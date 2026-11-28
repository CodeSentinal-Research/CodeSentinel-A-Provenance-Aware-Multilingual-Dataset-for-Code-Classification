Here's the JavaScript code for the problem:

// Definition for a binary tree node.
function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}

function solve(root) {
    let sum = 0;
    let result = new TreeNode(0);
    dfs(root, result);
    return result;
}

function dfs(node, result) {
    if (node === null) return;
    dfs(node.left, result);
    sum += node.val;
    node.val = sum;
    dfs(node.right, result);
}

This code defines a binary tree node with three properties: `val`, `left`, and `right`. It then defines the `solve` function, which takes a root node of a binary search tree and returns the root node of a cumulative sum tree.

The `solve` function uses a depth-first search (DFS) to traverse the binary search tree, and for each node, it calculates the sum of all nodes smaller than or equal to the current node. The sum is stored in the `sum` variable.

Then, it calls the `dfs` function to start the DFS from the root node. In `dfs`, it first recursively calls `dfs` for the left child node, then updates the value of the current node to the `sum` variable, and finally recursively calls `dfs` for the right child node.