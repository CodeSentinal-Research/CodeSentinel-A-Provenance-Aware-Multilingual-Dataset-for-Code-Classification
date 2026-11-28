Here is a solution for the problem using JavaScript. This solution uses a recursive approach to find the longest alternating even-odd path in a binary tree.

class Node {
  constructor(data, left = null, right = null) {
    this.data = data;
    this.left = left;
    this.right = right;
  }
}

function longestAlternatingPath(root) {
  if (root === null) {
    return 0;
  }

  let leftEven = longestAlternatingPath(root.left) + 1;
  let leftOdd = longestAlternatingPath(root.left.right) + 1;
  let leftNull = longestAlternatingPath(root.left.left) + 1;

  let rightEven = longestAlternatingPath(root.right) + 1;
  let rightOdd = longestAlternatingPath(root.right.left) + 1;
  let rightNull = longestAlternatingPath(root.right.right) + 1;

  let maxPath = Math.max(leftEven, leftOdd, leftNull, rightEven, rightOdd, rightNull);

  return maxPath;
}

In this code, a Node class is defined with left and right properties which are references to the left and right children of the node.

The longestAlternatingPath function is defined to find the longest alternating even-odd path in a binary tree. It uses recursion to traverse the tree and find the longest path for each node. It then returns the maximum of the three paths: one for each possible alternation of even and odd numbers (leftEven, leftOdd, rightEven, rightOdd, leftNull, rightNull).

You can call this function with a binary tree as the root node.

Please note that this code assumes you have a Binary Tree defined and can use methods to create and manipulate the binary tree such as `Node` and `root`.