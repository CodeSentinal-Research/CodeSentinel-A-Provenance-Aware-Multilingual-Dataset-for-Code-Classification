Here is a JavaScript solution using Breadth-First Search (BFS) strategy.

// Define a Node
function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val);
    this.left = (left===undefined ? null : left);
    this.right = (right===undefined ? null : right);
}

var rightSideView = function(root) {
    if(root === null) return [];
    let queue = [root];
    let res = [];
    while(queue.length > 0){
        let node = queue.shift();
        res.push(node.val); // add the value of the last node in the queue to the result list
        if(node.right !== null) queue.push(node.right); // push the right child of current node into the queue
        if(node.left !== null) queue.push(node.left); // push the left child of current node into the queue
    }
    return res;
};

In the code above, we use a queue to perform a Breadth-First Search. We start from the root, then process all the nodes on the current level before moving on to the next level. At each level, we only add the rightmost node from the current level to our result list.

For example, given the following binary tree:
    1
   / \
  2   3
 / \   \
4   5   6
The right-side view of the tree would be [1, 3, 6]

Remember that this solution is based on the level order traversal of binary trees. If the tree was in a perfect binary tree, each level would be visited in increasing order, and the rightmost node in each level would be the right-most node of the binary tree.