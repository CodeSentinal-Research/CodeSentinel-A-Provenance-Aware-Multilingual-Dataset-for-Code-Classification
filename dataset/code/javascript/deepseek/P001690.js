Here is a JavaScript solution for the problem. This solution uses Depth First Search (DFS) to visit every node in the binary tree. For each node, we calculate the maximum sum of the subtree which is the max of the sum of the subtree, sum of the left child + sum of the right child + the value of the node. This is because the sum of a subtree is the sum of all nodes in the subtree, so we need to consider all the nodes in the subtree.

// Definition for a binary tree node.
function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}

let maxSum = Number.MIN_SAFE_INTEGER;

function maxSumBST(root) {
    if (!root) {
        return maxSum;
    }

    let res = {};

    // DFS to find min, max and sum of the tree
    let { min, max, sum } = dfs(root);

    // If the tree is a valid BST, update maxSum
    if (maxSum < sum) {
        maxSum = sum;
    }

    return maxSum;
}

function dfs(node) {
    if (!node) {
        return { min: Number.MAX_SAFE_INTEGER, max: Number.MIN_SAFE_INTEGER, sum: 0 };
    }

    let left = dfs(node.left);
    let right = dfs(node.right);

    if (left.max < node.val && right.min > node.val) {
        let sum = left.sum + right.sum + node.val;
        if (sum > maxSum) {
            maxSum = sum;
        }

        return {
            min: Math.min(node.val, left.min),
            max: Math.max(node.val, right.max),
            sum
        };
    }

    return { min: 0, max: 0, sum: 0 };
}

This code should work for the provided constraints. However, if you have a large number of nodes and the input is too large, you may need to optimize the depth first search to avoid stack overflow.