Here is the JavaScript code to construct a binary tree from preorder and inorder traversals:

class Node {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

function preOrder(arr) {
  if (arr.length == 0) {
    return null;
  }
  let root = new Node(arr[0]);
  let index = arr.indexOf(arr[0]);
  let left = preOrder(arr.slice(1, index + 1));
  let right = preOrder(arr.slice(index + 1));
  root.left = left;
  root.right = right;
  return root;
}

function inOrder(arr, index) {
  if (arr.length == 0) {
    return null;
  }
  let root = new Node(arr[index[0]]);
  let left = inOrder(arr.slice(0, index[0]), [0, index[0]]);
  let right = inOrder(arr.slice(index[0] + 1), [index[0] + 1, arr.length]);
  root.left = left;
  root.right = right;
  return root;
}

let arrPreorder = process.argv[2].split(' ').map(Number);
let arrInorder = process.argv[3].split(' ').map(Number);
let tree = preOrder(arrPreorder);
let inorderIndexes = [];
let inorderCount = 0;

function inorder(node) {
  if (node != null) {
    inorder(node.left);
    inorderIndexes[inorderCount++] = node.data;
    inorder(node.right);
  }
}

inorder(tree);

console.log('Inorder traversal:', inorderIndexes.join(' '));

This code creates a Node class to represent each node in the binary tree. The preOrder function is used to construct a binary tree from the preorder traversal. The inOrder function is used to construct a binary tree from the inorder traversal. The inorderIndexes array is used to store the inorder traversal and the inorderCount variable is used to keep track of the current index in the inorder traversal array. The inorder function is a recursive function that visits each node in the binary tree in order (inorder traversal).

To run the code, you can pass the preorder and inorder traversals as command line arguments. For example, if you have preorder traversal `1 2 4 5 3` and inorder traversal `4 2 5 1 3`, you can run the code with the following command:

node filename.js "1 2 4 5 3" "4 2 5 1 3"

Please replace `filename` with the name of the JavaScript file you are running.