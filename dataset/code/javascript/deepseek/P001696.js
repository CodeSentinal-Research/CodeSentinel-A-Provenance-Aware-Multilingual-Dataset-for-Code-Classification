const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let n;
rl.once('line', line => {
  n = parseInt(line);
  let tree = [];
  let leafStrings = [];
  let minString = '';
  let minLen = Infinity;

  for (let i = 0; i < n; i++) {
    tree[i] = rl.readLine().split(' ');
  }

  function traverse(node, string) {
    if (tree[node].length === 0) {
      leafStrings.push(string);
    } else {
      let left = tree[node][0];
      let right = tree[node][1];
      traverse(left, string + left);
      if (right) traverse(right, string + right);
    }
  }

  traverse(0, '');

  leafStrings.sort();

  leafStrings.forEach((str, i) => {
    if (str.length < minLen) {
      minLen = str.length;
      minString = str;
    }
  });

  console.log(minString);

  rl.close();
});

In this code, we read the tree data from the standard input, then use a depth-first search to traverse the tree and collect all leaf-to-root paths. We then sort the leaf paths and find the lexicographically smallest one. The sorted list of leaf paths can be used to answer the problem.