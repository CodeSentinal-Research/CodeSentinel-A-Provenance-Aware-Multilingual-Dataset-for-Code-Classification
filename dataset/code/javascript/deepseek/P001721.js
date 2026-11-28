Here is the JavaScript code for the problem:

const fs = require('fs');

const input = fs.readFileSync('input.txt', 'utf8');
const [N] = input.split('\n').map(Number);

class Node {
  constructor(data, left = null, right = null) {
    this.data = data;
    this.left = left;
    this.right = right;
  }
}

const nodes = [];
for (let i = 0; i < N; i++) {
  nodes.push(new Node(i));
}

for (let i = 0; i < N; i++) {
  const [parent, left, right] = input.split('\n')[i + 1].split(' ');
  const parentIndex = Number(parent);
  if (left !== 'Leaf') {
    nodes[parentIndex].left = nodes[Number(left)];
  }
  if (right !== 'Leaf') {
    nodes[parentIndex].right = nodes[Number(right)];
  }
}

let sum = 0;
let depth = 1;
let level = 0;
let currentNode = nodes[0];

while (currentNode !== null) {
  if (depth % 2 === 1) {
    sum += currentNode.data;
  }
  level++;
  depth = level === 1 ? 2 : level;
  if (currentNode.left !== null) {
    currentNode = currentNode.left;
  } else if (currentNode.right !== null) {
    currentNode = currentNode.right;
  } else {
    currentNode = null;
  }
}

console.log(sum);

This code reads the input from a file named 'input.txt', reads the number of nodes N, and creates a binary tree using the given node values. Then it calculates the sum of the values of the nodes at odd levels.