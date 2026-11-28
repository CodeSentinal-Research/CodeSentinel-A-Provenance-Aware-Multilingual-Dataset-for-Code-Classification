Here is the JavaScript code for the problem:

class TreeNode {
  constructor(val = 0, left = null, right = null) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

function maxWidth(root) {
  if (!root) return 0;

  let queue = [root];
  let maxWidth = 0;

  while (queue.length) {
    let size = queue.length;
    let min = queue[0].val;
    let max = queue[size - 1].val;

    for (let i = 0; i < size; i++) {
      let node = queue.shift();

      if (node.val > max) {
        max = node.val;
      }

      if (node.left) {
        queue.push(node.left);
      }

      if (node.right) {
        queue.push(node.right);
      }
    }

    maxWidth = Math.max(maxWidth, max - min + 1);
  }

  return maxWidth;
}

let root = new TreeNode(1);
root.left = new TreeNode(3);
root.right = new TreeNode(5);
root.left.left = new TreeNode(6);
root.left.right = new TreeNode(2);
root.left.right.left = new TreeNode(7);
root.left.right.right = new TreeNode(4);
root.right.right = new TreeNode(1);
root.right.right.left = new TreeNode(0);
root.right.right.left.left = new TreeNode(8);
console.log(maxWidth(root));

This solution uses a Breadth-First Search (BFS) strategy to find the maximum width of the binary tree. It starts by adding the root node to the queue. In each iteration of the while loop, we find the minimum and maximum values (which represent the leftmost and rightmost nodes in the current level of the tree) and calculate the maximum width of the current level. We then add all the children of the current node to the queue for the next iteration.

This solution assumes that the input is a root of a binary tree. If the input is a tree represented in an array, you would need to create the tree from that array. Also, this solution assumes that the input does not contain any missing nodes. If the input might contain missing nodes, you would need to handle them separately.