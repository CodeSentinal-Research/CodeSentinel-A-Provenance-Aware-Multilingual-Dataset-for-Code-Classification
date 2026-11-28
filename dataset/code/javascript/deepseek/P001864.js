Here is a JavaScript solution that uses the Binary Search Tree concept to solve this problem. The idea is to find the maximum depth of the BST (i.e., the number of edges in the longest path from root to a leaf), and then multiply it by 2 (since each comparison to a parent node increases the search cost by 1), and subtract 1 (since we're comparing the root node with itself).

const fs = require('fs');
const readline = require('readline');

const input = fs.createReadStream('input.txt');
const rl = readline.createInterface({
  input: input,
  crlfDelay: Infinity
});

let numNodes;
let nodeValues;

rl.on('line', (line) => {
  if (numNodes === undefined) {
    numNodes = parseInt(line, 10);
  } else {
    nodeValues = line.split(' ').map(val => parseInt(val, 10));
    const maxDepth = getMaxDepth(nodeValues, 0, 1);
    console.log(2 * maxDepth - 1);
  }
});

function getMaxDepth(arr, start, end) {
  if (start === end) {
    return 0;
  }

  let maxDepth = 0;
  const mid = Math.floor((start + end) / 2);
  const leftMaxDepth = getMaxDepth(arr, start, mid);
  const rightMaxDepth = getMaxDepth(arr, mid + 1, end);

  maxDepth = Math.max(leftMaxDepth, rightMaxDepth);

  return maxDepth + 1;
}

This solution uses the readline module to read the input from a file named 'input.txt'. The `line` event handler is called for each line in the input file. The first line (`numNodes`) is read and stored, and the rest of the lines are stored in the `nodeValues` array. Once the input has been read, the `getMaxDepth` function is called, which recursively finds the maximum depth of the BST.

Note: This solution assumes that the input file is in the same directory as the script, and has the file name 'input.txt'. If the input file is not in the same directory or has a different name, you will need to adjust the path to the input file in the code.