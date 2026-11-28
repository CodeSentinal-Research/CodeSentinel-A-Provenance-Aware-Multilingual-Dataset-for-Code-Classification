let tree = null;

class Node {
  constructor(data) {
    this.data = data;
    this.children = [];
  }
}

function addChild(parent, child) {
  parent.children.push(child);
}

function findKthAncestor(node, target, k) {
  // base case
  if (node === null) {
    return null;
  }

  // check if current node is the target node
  if (node.data === target) {
    return k === undefined ? node : (k === 0 ? node.data : findKthAncestor(node.children[k-1], target, k-1));
  }

  let res = null;

  for (let i = node.children.length - 1; i >= 0; i--) {
    res = findKthAncestor(node.children[i], target, k);
    if (res !== null) {
      break;
    }
  }

  return res;
}

function processInput(input) {
  const [n, lines] = input.split('\n');

  tree = new Node(lines[0]);

  let current = tree;

  for (let i = 1; i < lines.length; i++) {
    const line = lines[i].split(' ');
    for (let j = 1; j < line.length; j++) {
      const child = new Node(line[j]);
      addChild(current, child);
    }
    current = current.children[0];
  }

  const [target, k] = lines[lines.length - 1].split(' ');

  console.log(findKthAncestor(tree, target, parseInt(k)));
}

process.stdin.on('data', processInput);