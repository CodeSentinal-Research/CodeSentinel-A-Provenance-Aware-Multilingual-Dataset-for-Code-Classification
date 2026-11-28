const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let tree = [];
let result = [];

rl.on('line', (line) => {
  tree.push(parseInt(line));
  if (tree.length === 2 ** tree.length - 1) {
    countNodes(tree, 0, 0);
    rl.close();
  }
});

function countNodes(tree, index, level) {
  if (tree[index] !== undefined) {
    countNodes(tree, tree[index] * 2 + 1, level + 1);
    countNodes(tree, tree[index] * 2 + 2, level + 1);
  } else {
    result[level] = (result[level] || 0) + 1;
  }
}
This code reads the complete binary tree from the input and then counts the nodes in each level using a depth-first search. The code starts with an empty tree and reads the input one line at a time. When the input is completely read, it calls the `countNodes` function to count the nodes in each level. The `countNodes` function recursively counts the nodes at each level, and the results are stored in the `result` array.