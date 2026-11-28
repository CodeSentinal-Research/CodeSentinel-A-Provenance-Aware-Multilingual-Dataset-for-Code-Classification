Here's a simple JavaScript code that implements the solution. This code first reads the input, then constructs the binary tree from the input. After that, it checks whether every internal node has exactly one child.

let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let tree = {};
let depths = {};
let maxDepth = -1;

rl.on('line', (line) => {
  let nodes = line.split(' ');
  let current = tree;

  nodes.forEach(node => {
    if (!current[node]) {
      current[node] = {};
    }
    current = current[node];
  });
});

rl.on('close', () => {
  let depthsCount = Object.values(deps).reduce((a, b) => a + b);

  console.log(depthsCount === N ? 'YES' : 'NO');

  rl.close();
});

This code assumes that you have a Node.js environment set up with the Readline module. The code reads lines from standard input, constructing a binary tree from them. After all lines are read, it calculates the count of depths and compares it with the number of nodes in the tree (`N`). If the count of depths is equal to `N`, it prints 'YES', otherwise it prints 'NO'.

Please replace `N` with the actual number of nodes in the tree before running the code.