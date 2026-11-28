Here is a solution for the problem:

function constructBST(matrix) {
  const nodes = new Map();

  // Create nodes for each node in the matrix
  for (let i = 0; i < matrix.length; i++) {
    nodes.set(i, { val: matrix[i] });
  }

  // Create edges for each node in the matrix
  for (let i = 0; i < matrix.length; i++) {
    if (matrix[i] !== -1) {
      nodes.get(i).left = nodes.get(matrix[i]);
      nodes.get(matrix[i]).right = nodes.get(i);
    }
  }

  // Find the root of the tree
  let rootId = -1;
  for (let i = 0; i < matrix.length; i++) {
    if (nodes.get(i).left === undefined) {
      rootId = i;
      break;
    }
  }

  // Check if the tree is valid
  if (rootId === -1) {
    return 'IMPOSSIBLE';
  }

  return nodes.get(rootId);
}

console.log(constructBST([-1, 0, 0, 1, 2, 3]));
This solution constructs a binary search tree from the ancestor matrix. It first creates nodes for each node in the matrix and then creates edges for each node in the matrix. It then finds the root of the tree and checks if the tree is valid.

Note: The provided code assumes that the ancestor matrix is a binary tree with distinct keys. If the keys are not distinct, the code may not work correctly.