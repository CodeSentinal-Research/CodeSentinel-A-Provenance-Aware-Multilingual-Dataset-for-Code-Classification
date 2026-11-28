Sure, here is a simple JavaScript solution for the problem. This solution uses level order traversal to find the maximum width of the binary search tree. We use an array to store the nodes at each level.

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

  while (queue.length > 0) {
    let size = queue.length;
    maxWidth = Math.max(maxWidth, size);

    while (size > 0) {
      let node = queue.shift();
      if (node.left) queue.push(node.left);
      if (node.right) queue.push(node.right);
      size--;
    }
  }

  return maxWidth;
}

In this solution, we create a `TreeNode` class to represent the nodes of the binary search tree. Then we define a `maxWidth` function that takes the root of the binary search tree as input.

In the `maxWidth` function, we use a level order traversal to find the maximum width of the binary search tree. We use a queue to store the nodes at each level and calculate the maximum width at each level.

Finally, we return the maximum width.

This solution assumes that the input is a root node of a binary search tree.