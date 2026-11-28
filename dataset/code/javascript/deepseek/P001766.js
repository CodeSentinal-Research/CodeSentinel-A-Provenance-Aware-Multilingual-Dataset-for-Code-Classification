Here is a JavaScript solution for the given problem. This solution uses Breadth-First Search (BFS) to find the median of each level. It uses a queue to keep track of the nodes at each level.

class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

function solve(root) {
    if (!root) {
        return;
    }

    let queue = [root];
    let level = 0;
    while (queue.length > 0) {
        let size = queue.length;
        let nums = [];
        for (let i = 0; i < size; i++) {
            let node = queue.shift();
            nums.push(node.val);
            if (node.left) {
                queue.push(node.left);
            }
            if (node.right) {
                queue.push(node.right);
           
            }
        }
        nums.sort((a, b) => a - b);
        let median;
        if (nums.length % 2 === 0) {
            median = (nums[nums.length / 2 - 1] + nums[nums.length / 2]) / 2;
        } else {
            median = nums[Math.floor(nums.length / 2)];
        }
        console.log(`Level ${level}: ${median}`);
        level++;
    }
}

This solution first checks if the root node exists. If not, it returns immediately. Then, it initializes a queue with the root node and a level variable. The solution runs in a while loop until the queue is empty. In each iteration, it processes all the nodes at the current level, pushes their children to the end of the queue, and updates the level. Finally, it prints the median for the current level and moves to the next level.

Note: The given tree is a binary tree where each node has at most two children. Also, the input does not contain any duplicate values or invalid inputs.