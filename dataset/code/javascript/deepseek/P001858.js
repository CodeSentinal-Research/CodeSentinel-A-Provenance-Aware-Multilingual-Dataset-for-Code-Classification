Here is the JavaScript code that solves the problem:

class TreeNode {
    constructor(val = 0, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    index = 0;

    constructMaximumBinaryTree(nums) {
        if (!nums.length) {
            return null;
        }

        let maxIndex = nums.indexOf(Math.max(...nums));
        let root = new TreeNode(nums[maxIndex]);

        root.left = this.constructMaximumBinaryTree(nums.slice(0, maxIndex));
        root.right = this.constructMaximumBinaryTree(nums.slice(maxIndex + 1));

        return root;
    }
}

let solution = new Solution();

process.stdin.resume();
process.stdin.on('data', (chunk) => {
    let input = chunk.toString().trim();
    if (input !== '') {
        let nums = input.split(' ').map(item => parseInt(item));
        let root = solution.constructMaximumBinaryTree(nums);
        // Print the reconstructed BST
        console.log(root);
    }
});

In this code, we create a `TreeNode` class to represent each node in the binary tree. The `Solution` class has a method `constructMaximumBinaryTree` that uses depth-first search to reconstruct the maximum binary tree from the level order traversal. The `index` variable is used to keep track of the index in the level order traversal that we're currently at. 

To read input from standard input, we're using `process.stdin.resume()` and `process.stdin.on('data', ...)`. When we're ready to read more input, we simply call the `constructMaximumBinaryTree` method with the current level order traversal.