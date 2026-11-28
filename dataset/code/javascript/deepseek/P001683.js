Here is the JavaScript code to solve the problem:

let visitedNodes = new Set();
let deepestLeftLeafNode = null;

class TreeNode {
  constructor(val = 0, left = null, right = null) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

function findDeepestLeftLeaf(root) {
  if (!root) {
    return;
  }
  visitedNodes.add(root);
  if (root.left && !visitedNodes.has(root.left)) {
    findDeepestLeftLeaf(root.left);
  } else if (root.left && root.right && !visitedNodes.has(root.right)) {
    if (!deepestLeftLeafNode || root.left.val < deepestLeftLeafNode.val) {
      deepestLeftLeafNode = root.left;
    }
  }
  if (root.right && !visitedNodes.has(root.right)) {
    findDeepestLeftLeaf(root.right);
  }
}

let root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(3);
root.left.left = new TreeNode(4);
root.left.right = new TreeNode(5);
root.right.left = new TreeNode(6);
root.right.right = new TreeNode(7);
findDeepestLeftLeaf(root);
console.log(deepestLeftLeafNode ? deepestLeftLeafNode.val : 'None');

In this code, we are using a Depth-First Search (DFS) approach. The DFS is a way of traversing or searching tree data structures. In the given code, we are traversing the binary tree using DFS. We keep a Set to keep track of visited nodes. For each node, we first check if it's a visited node. If it's not visited, then we mark it as visited and perform DFS on its children. If it's a visited node, we check if it's a leaf node (left child). If it's not a leaf node, we update the deepestLeftLeafNode if it's smaller than the current deepestLeftLeafNode.