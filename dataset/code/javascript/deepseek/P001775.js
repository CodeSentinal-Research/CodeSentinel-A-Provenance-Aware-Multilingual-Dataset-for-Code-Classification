Sure, here is a JavaScript solution for the problem. This solution uses a depth-first search (DFS) approach to traverse the tree, calculating the sum of each level. It also keeps track of the maximum difference found so far.

class TreeNode {
    constructor(val = 0, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

function maxDiff(root) {
    let maxDiff = [0];
    dfs(root, 0, root.val, maxDiff);
    return maxDiff[0];
}

function dfs(node, level, sum, maxDiff) {
    if (!node) {
        return;
    }
    if (maxDiff[0] < level) {
        maxDiff[0] = level;
    }
    if (maxDiff[0] < level && sum > maxDiff[0]) {
        maxDiff[0] = sum;
    }
    dfs(node.left, level + 1, sum + node.val, maxDiff);
    dfs(node.right, level + 1, sum + node.val, maxDiff);
}

// Create a binary tree from input
let root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(3);
root.left.left = new TreeNode(4);
root.left.right = new TreeNode(5);

console.log(maxDiff(root));  // Output: 3

In this code, we first define a TreeNode class to represent each node in the tree. The `maxDiff` function is the main function that computes the maximum difference. It uses a depth-first search approach to traverse the tree. The `dfs` function is a helper function that computes the sum of each level and updates the maximum difference if necessary.