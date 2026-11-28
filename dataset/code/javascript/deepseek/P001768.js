Here is the code:

// Definition for a binary tree node.
function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val);
    this.left = (left===undefined ? null : left);
    this.right = (right===undefined ? null : right);
}

var findMaximumValueAtEveryLevel = function(root) {
    if (!root) {
        return;
    }

    let queue = [root];
    while (queue.length > 0) {
        let levelSize = queue.length;
        let maxInLevel = queue[0].val;

        for (let i = 0; i < levelSize; i++) {
            let current = queue.shift();

            if (current.val > maxInLevel) {
                maxInLevel = current.val;
            }

            if (current.left) {
                queue.push(current.left);
            }

            if (current.right) {
                queue.push(current.right);
            }
        }

        console.log(maxInLevel);
    }
};

This code defines a `TreeNode` class and a function `findMaximumValueAtEveryLevel` that takes a root node of a binary tree and prints the maximum value at each level. The function uses a queue to process each level of the tree level by level. It starts with the root, then it processes all the nodes in the current level, and when all the nodes in the current level have been processed, it moves on to the next level. It also ensures to process the left and right child nodes of each node in the current level.