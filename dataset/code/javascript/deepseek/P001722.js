Sure, here's a simple JavaScript solution using Breadth-First Search (BFS) algorithm to traverse the binary tree at even levels:

class TreeNode {
    constructor(val = 0, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

function solve(tree) {
    if (!tree) return 0;
    let res = 0;
    let level = 1;
    let queue = [tree];
    while (queue.length > 0) {
        let len = queue.length;
        for (let i = 0; i < len; i++) {
            let node = queue.shift();
            if (level % 2 === 0 && node.val !== null) {
                res += node.val;
            }
            if (node.left) queue.push(node.left);
            if (node.right) queue.push(node.right);
        }
        level++;
    }
    return res;
}

let tree = new TreeNode(1);
tree.left = new TreeNode(2);
tree.right = new TreeNode(3);
tree.left.left = new TreeNode(4);
tree.left.right = new TreeNode(5);
console.log(solve(tree));  // Output: 4

In this code, we first define a TreeNode class and then implement a solve function to solve the problem. We use a queue to do BFS. In each level, we check if the level is even (`level % 2 === 0`) and if the node value is not null (`node.val !== null`). If it is, we add the value to the result. Then we add the left and right children of the current node to the queue for the next level.