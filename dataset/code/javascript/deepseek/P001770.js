Here is the JavaScript code for the problem.

function createTree(nodes) {
  const tree = [];
  for (let i = 0; i < nodes.length; i++) {
    if (nodes[i] === -1) {
      tree.push(null);
    } else {
      tree.push({
        value: nodes[i],
        left: null,
        right: null,
      });
    }
  }

  return tree;
}

function replaceNodes(tree, index, sum) {
  if (tree[index] === null) {
    return;
  }

  tree[index].value = sum;
  replaceNodes(tree, tree[index].left, index * 2 + 1, sum);
  replaceNodes(tree, tree[index].right, index * 2 + 2, sum);
}

function solve(N, nodes) {
  const tree = createTree(nodes);
  let maxIndex = 0;
  while (tree[maxIndex] !== null) {
    maxIndex++;
  }
  maxIndex--;

  replaceNodes(tree, maxIndex, 0);

  tree.forEach((node, index) => {
    if (index !== maxIndex) {
      console.log(node.value);
    }
  });
}

process.stdin.setEncoding('utf8');
process.stdin.on('data', (data) => {
  const [N, ...nodes] = data.split('\n');
  solve(N, nodes);
});

This script reads the input from stdin and calls the solve function. The solve function creates the tree and replaces each node with the sum of other nodes at the same level. The transformed tree is then printed to stdout.