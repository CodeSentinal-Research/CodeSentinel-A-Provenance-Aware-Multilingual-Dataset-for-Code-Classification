Here is a JavaScript solution that handles the given problem:

const fs = require('fs');

process.stdin.setEncoding('utf-8');

let inputString = '';
process.stdin.on('data', (inputStdinBuffer) => {
  inputString += inputStdinBuffer;
});

process.stdin.on('end', () => {
  const lines = inputString.trim().split('\n');
  const N = parseInt(lines[0], 10);
  const tree = lines[1].split(' ').map(Number);
  const X = parseInt(lines[2], 10);
  
  console.log(findSmallest(tree, X));
});

function findSmallest(tree, X) {
  if (tree.length === 0) {
    return 'NONE';
  }
  
  let left = 0;
  let right = tree.length - 1;
  
  while (left < right) {
    const mid = Math.floor((left + right) / 2);
    
    if (tree[mid] <= X) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  
  return tree[left] > X ? tree[left] : 'NONE';
}

This program reads the input as a binary search tree and a value X, then uses a binary search to find the smallest key that is greater than X. If no such key exists, it returns 'NONE'.