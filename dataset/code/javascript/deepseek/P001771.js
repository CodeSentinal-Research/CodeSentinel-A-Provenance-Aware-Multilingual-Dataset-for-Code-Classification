Sure, here is a simple JavaScript solution using a Breadth-First Search (BFS) strategy to traverse the binary tree and calculate the vertical sums. The code assumes that the tree is represented as a binary tree object (each node of the tree has a value and left and right children).

class TreeNode {
  constructor(val = 0, left = null, right = null) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

function solve(root) {
  if (!root) {
    return;
  }

  let queue = [root];
  let sums = new Map();

  while (queue.length) {
    let level = new Map();
    let currentLevel = queue[0];
    queue.shift();

    while (currentLevel) {
      if (!level.has(currentLevel.val)) {
        level.set(currentLevel.val, 1);
      } else {
        level.set(currentLevel.val, level.get(currentLevel.val) + 1);
      }

      if (currentLevel.left) {
        queue.push(currentLevel.left);
      }
      if (currentLevel.right) {
        queue.push(currentLevel.right);
      }

      currentLevel = currentLevel.left || currentLevel.right;
    }

    for (let [sum, count] of level.entries()) {
      if (sums.has(sum)) {
        sums.get(sum).push(count);
      } else {
        sums.set(sum, [count]);
      }
    }
  }

  for (let [sum, counts] of sums.entries()) {
    console.log(sums.get(sum).join(' '));
  }
}

This code uses a Breadth-First Search strategy to traverse the binary tree and calculate the vertical sums. The sums are stored in a Map where the key is the sum of node values and the value is an array of counts for each vertical column. The counts are then printed out.

Please note that the input and output are not handled here. You would need to add input handling code to read the tree from the standard input, and you would need to format the output to the standard output.