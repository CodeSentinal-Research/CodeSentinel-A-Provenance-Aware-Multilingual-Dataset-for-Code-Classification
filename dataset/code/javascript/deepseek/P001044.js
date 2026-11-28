Here is the JavaScript code for the given problem. The code assumes that the binary heap is represented as an array and we are given the index of a node. The code calculates the level of the node where the root is at level 0.

// Assuming that the binary heap is represented as an array and we are given the index of a node

const findLevel = (heap, node) => {
  let level = 0;

  while (node > 0) {
    node = Math.floor(node / 2);
    level++;
  }

  return level;
}

// Example usage:
const heap = [90, 70, 50, 20, 10, 5, 1]; // Binary heap representation
const nodeIndex = 5; // Index of the node

console.log(findLevel(heap, nodeIndex)); // Output: 3

This code works by repeatedly dividing the node by 2 (since each level is one less than the previous one), and incrementing the level as we go. This will eventually reach the level where the node is at the root, which is at level 0.