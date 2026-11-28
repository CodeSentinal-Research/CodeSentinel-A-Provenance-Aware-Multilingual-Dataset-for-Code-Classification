Here is the JavaScript code that performs a reverse level order traversal of a binary tree.

function Node(data, left=null, right=null) {
  this.data = data;
  this.left = left;
  this.right = right;
}

function LevelOrderTraversal(root) {
  if (root === null) {
    return;
  }

  let queue = [root];
  let result = [];
  
  while (queue.length > 0) {
    let node = queue.shift();
    result.push(node.data);
    
    if (node.left !== null) {
      queue.push(node.left);
    }
    if (node.right !== null) {
      queue.push(node.right);
    }
  }

  result.reverse();
  return result;
}

// Input handling.
let N = parseInt(readline());
let root = null;

for (let i = 0; i < N; i++) {
  let line = readline().split(' ');
  let data = parseInt(line[0]);
  let left = (line[1] === 'null') ? null : new Node(parseInt(line[1]));
  let right = (line[2] === 'null') ? null : new Node(parseInt(line[2]));
  let node = new Node(data, left, right);
  
  if (i === 0) {
    root = node;
  }
}

console.log(LevelOrderTraversal(root));

In this code, we first define a Node constructor for creating new nodes in the binary tree. The LevelOrderTraversal function performs a level order traversal starting from the deepest level and ending at the root. We use a queue to perform level order traversal. The `readline()` function is a built-in JavaScript function that reads from the standard input (usually the console or command line).