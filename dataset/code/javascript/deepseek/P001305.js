Here is the JavaScript code to solve the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of characters: ', (n) => {
  rl.question('Enter characters frequencies: ', (chars) => {
    const frequencies = chars.split(' ').map(Number);

    const huffmanTree = buildHuffmanTree(frequencies);
    const cost = calculateCost(huffmanTree, frequencies);

    console.log(cost);

    rl.close();
  });
});

function buildHuffmanTree(frequencies) {
  const nodes = [];

  for (let char in frequencies) {
    nodes.push(new Node(char, frequencies[char]));
  }

  while (nodes.length > 1) {
    nodes.sort((a, b) => a.frequency - b.frequency);

    const left = nodes.shift();
    const right = nodes.shift();

    const parent = new Node(null, left.frequency + right.frequency);
    parent.left = left;
    parent.right = right;

    nodes.push(parent);
  }

  return nodes[0];
}

function calculateCost(node, frequencies) {
  let cost = 0;

  const walk = (node, prefix = '') => {
    if (node.left === null && node.right === null) {
      cost += frequencies[node.char] * prefix.length;
    } else {
      walk(node.left, prefix + '0');
      walk(node.right, prefix + '1');
    }
  };

  walk(node);

  return cost;
}

class Node {
  constructor(char, frequency) {
    this.char = char;
    this.frequency = frequency;
    this.left = null;
    this.right = null;
  }
}

This code first reads the number of characters and their frequencies from the input. It then builds the Huffman tree and calculates the cost of the encoding. The `buildHuffmanTree` function constructs the Huffman tree based on the input frequencies. The `calculateCost` function calculates the cost of the encoding by traversing the Huffman tree and summing up the weighted path lengths of each character.