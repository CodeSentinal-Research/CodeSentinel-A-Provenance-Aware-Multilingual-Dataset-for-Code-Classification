Here's the JavaScript code for the problem.

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var zigzagLevelOrder = function(root) {
    if (!root) {
        return [];
    }

    let result = [];
    let queue = [root];
    let level = 0;

    while(queue.length > 0) {
        let len = queue.length;
        let subArray = [];

        for(let i = 0; i < len; i++) {
            let node = queue.shift();

            subArray.push(node.val);

            if(node.left) {
                queue.push(node.left);
            }

            if(node.right) {
                queue.push(node.right);
           
            }
        }

        if(level % 2 === 1) {
            subArray.reverse();
        }

        level++;
        result.push(subArray);
    }

    return result;
};

In this solution, we use a queue to perform level order traversal. For each level, we first push all the nodes into the queue. Then we create a subarray for the current level and add the nodes in the order. If the level is odd, we reverse the subarray before adding it to the result. Finally, we increment the level and add the subarray to the result.