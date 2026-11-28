Here is the JavaScript solution for the given problem:

function maxPathSum(root) {
    // Initial max sum
    let maxSum = -Infinity;

    // Recursive function to calculate max sum
    function maxPath(node) {
        if (!node) {
            return 0;
        }

        // Calculate max sum for left and right child plus current node
        let left = Math.max(maxPath(node.left), 0);
        let right = Math.max(maxPath(node.right), 0);

        // Update max sum
        maxSum = Math.max(maxSum, left + right + node.val);

        // Return max path sum for current node
        return Math.max(left + node.val, right + node.val);
    }

    maxPath(root);
    return maxSum;
}
This solution uses recursive depth-first search approach to find the maximum path sum in a binary tree. The maxSum variable is used to store the maximum path sum found so far. The maxPath function is recursive and calculates the maximum sum for the current node (including the current node) if it's included or excluded. The maxSum variable is updated if the current node's sum is greater than the maxSum. The return value from maxPath represents the maximum path sum for the current node.