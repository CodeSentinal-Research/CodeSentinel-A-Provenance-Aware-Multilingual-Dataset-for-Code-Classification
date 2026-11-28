Here is the JavaScript code for the problem:

function Node(data) {
  this.data = data;
  this.left = null;
  this.right = null;
}

function constructBST(postorder) {
  if (postorder.length === 0) {
    return null;
  }

  let root = new Node(postorder[postorder.length - 1]);

  let right = postorder.slice(0, postorder.length - 1);
  let left = [];

  while (true) {
    let next = right.pop();
    if (next.data > root.data) {
      root.right = new Node(next.data);
      break;
    }
    left.push(new Node(next.data));
  }

  root.left = constructBST(left);
  root.right = constructBST(right);

  return root;
}

function postOrder(node) {
  if (node === null) {
    return;
  }

  postOrder(node.left);
  postOrder(node.right);

  console.log(node.data);
}

let N = parseInt(readline());
let postorder = readline().split(' ').map(Number);
postorder.reverse();

let root = constructBST(postorder);
postOrder(root);

This code first defines a Node class, then constructBST function which takes a postorder array and returns a root node of the BST. This function first constructs the root node of the BST and then recursively constructs the left and right subtrees. Finally, it uses postOrder function to print the postorder traversal of the BST.

Please note, you need to define readline function for input handling in your environment, as this is a text-based environment, and readline is a built-in function in Node.js.