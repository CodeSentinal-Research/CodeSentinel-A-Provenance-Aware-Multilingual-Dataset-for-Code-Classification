Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let inputArr = [];

rl.on('line', (line) => {
  inputArr = [...inputArr, ...line.split(' ').map(Number)];
});

rl.on('close', () => {
  console.log(solve(inputArr));
  process.exit();
});

function solve(inputArr) {
  // create BST
  class Node {
    constructor(val, left = null, right = null) {
      this.val = val;
      this.left = left;
      this.right = right;
    }
  }

  const bst = new Node(inputArr[0]);
  let i = 1;

  // build BST from the second element onwards
  while(i < inputArr.length) {
    bst.left = new Node(inputArr[i]);
    i++;
    if(i < inputArr.length) {
      bst.right = new Node(inputArr[i]);
      i++;
    }
    bst = bst.right;
  }

  // check if it's a BST
  if(isValidBST(bst)) {
    return 'YES';
  } else {
    return 'NO';
  }
}

function isValidBST(node, min = null, max = null) {
  if (node === null) {
    return true;
  }
  if (min !== null && node.val <= min || max !== null && node.val > max) {
    return false;
  }
  return isValidBST(node.left, min, node.val) && isValidBST(node.right, node.val, max);
}
In this code, we first create a binary search tree. Then, we check whether this binary search tree is a valid level order traversal of a binary search tree or not. We use a helper function called `isValidBST` to check whether a given binary tree is a valid binary search tree or not.