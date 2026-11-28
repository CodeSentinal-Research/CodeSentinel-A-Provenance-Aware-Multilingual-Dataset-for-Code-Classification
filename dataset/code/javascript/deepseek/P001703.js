Here is the JavaScript code for your problem:

process.stdin.setEncoding('utf8');

const readline = require('readline');
const input = require('fs').createReadStream('input.txt');
const rl = readline.createInterface({
  input: input,
  terminal: false
});

let tree = {};
let maxDiff = -Infinity;

rl.on('line', (line) => {
  tree[line] = [];
  rl.once('line', () => {
    const [node, ...children] = tree[line];
    tree[line] = children.map(child => tree[child]);
  });
});

rl.once('line', (line) => {
  tree[line] = [];
  processTree(line, Infinity, -Infinity);
  console.log(maxDiff);
});

function processTree(node, min, max) {
  if (min > tree[node][0]) min = tree[node][0];
  if (max < tree[node][0]) max = tree[node][0];
  maxDiff = Math.max(maxDiff, max - min);
  tree[node].forEach(child => processTree(child, min, max));
}

In this code, we read the tree from the standard input, then process it. The processTree function is a recursive function that finds the maximum difference between any node and one of its descendants. It updates maxDiff whenever a larger difference is found.