Here is the JavaScript code that generates all unique Binary Search Trees containing values from 1 to N.

function TreeNode(val, left = null, right = null) {
  this.val = val;
  this.left = left;
  this.right = right;
}

function generateTrees(N) {
  if (N < 1) return [];
  return generateAll(1, N);

  function generateAll(start, end) {
    if (start > end) return [null];

    const allTrees = [];

    for (let i = start; i <= end; i++) {
      const leftTrees = generateAll(start, i - 1);
      const rightTrees = generateAll(i + 1, end);

      for (let l of leftTrees) {
        for (let r of rightTrees) {
          const root = new TreeNode(i);
          root.left = l;
          root.right = r;
          allTrees.push(root);
        }
      }
    }

    return allTrees;
  }
}

In this code, the function `generateTrees(N)` initiates the process by creating an empty array `allTrees` to hold all possible Binary Search Trees. The function `generateAll(start, end)` is recursively called for all possible values in the range [start, end]. If the range is empty (`start > end`), it means that we have reached a leaf node and we return a null node as it is a valid BST. For each of the possible values in the range, it generates all possible BSTs by recursively generating left and right subtrees, and for each possible left and right subtree, it creates a new BST with the current value as root.

Please note that this code only generates unique Binary Search Trees, so if the input is `N = 3`, the output will be a unique BST for each of 1, 2 and 3.