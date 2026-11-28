Here is the JavaScript code that will solve the problem. This code uses a recursive approach to flatten the binary tree into a linked list. It keeps track of the current node and its next node during the process.

class ListNode {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}

class TreeNode {
  constructor(x) {
    this.val = x;
    this.left = null;
    this.right = null;
  }
}

// Function to flatten the binary tree into a linked list
let flatten = function(root) {
  if (root == null) return null;

  // Find the tail of the list that will be used to construct the list
  let tail = new ListNode(root.val);

  // Traverse the left subtree and link the list and tree
  let left = flatten(root.left);
  if (left != null) {
    tail.next = left;
    tail = left;
  }

  // Traverse the right subtree and link the list and tree
  let right = flatten(root.right);
  if (right != null) {
    tail.next = right;
    tail = right;
 
  }

  // Return the head of the list
  return tail;
};

The `ListNode` class is used to represent each node in the linked list. Each `ListNode` instance has a `val` property (the value stored in the node) and a `next` property (the next node in the list).

The `TreeNode` class is used to represent each node in the binary tree. Each `TreeNode` instance has a `val` property (the value stored in the node) and two pointers for the left and right children.

In the `flatten` function, we first check if the root of the tree is null. If it is, we return null because the tree is empty. 

We then create a new `ListNode` that will be used to hold the first node in the flattened list. We also create a tail variable that will be used to keep track of the last node in the list.

We then traverse the left subtree and right subtree of the root and link the list and tree. The traversal process is done recursively to make sure all nodes in the left and right subtree are processed first. After the traversal is done, we return the tail of the list which is the last node in the flattened list.