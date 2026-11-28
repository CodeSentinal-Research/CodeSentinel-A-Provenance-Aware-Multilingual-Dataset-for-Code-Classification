Here is the JavaScript code:

function solve() {
  let n = parseInt(readline());
  let nodes = [];

  for (let i = 0; i < n; i++) {
    let line = readline().split(' ');
    nodes.push({value: line[0], left: line[1], right: line[2]});
  }

  let root = nodes[0];

  function maxWidth(node, depth) {
    if (!node) {
      return 0;
    }

    let left = maxWidth(node.left, depth + 1);
    let right = maxWidth(node.right, depth + 1);

    return Math.max(left, right) + 1;
  }

  console.log(maxWidth(root, 0));
}
This code reads the number of nodes and the details of each node, which includes the value and the indices of its left and right children. It then computes the maximum width of the binary tree using a depth-first search.