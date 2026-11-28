function solve() {
  let N = parseInt(readline());
  let tree = new Map();
  for (let i = 0; i < N; i++) {
    let line = readline().split(' ');
    tree.set(line[0], line.slice(1).map(Number));
  }
  let inOrder = inOrderTraversal(tree);
  let min = Math.min(...inOrder);
  let max = Math.max(...inOrder);
  let indexMin = inOrder.indexOf(min);
  let indexMax = inOrder.indexOf(max);
  if (indexMin > indexMax) {
    if (isValid(tree, min, max)) {
      print('YES');
    } else {
      print('NO');
    }
  } else {
    print('YES');
  }
}

function inOrderTraversal(tree) {
  let inOrder = [];
  function traverse(node) {
    for (let child in node) {
      if (child !== '0') {
        traverse(node[child]);
      }
    }
    inOrder.push(node.value);
  }
  traverse(tree);
  return inOrder;
}

function isValid(tree, min, max) {
  let queue = [[min, true]];
  while (queue.length > 0) {
    let [node, isLeft] = queue.pop();
    if (node.value < min || node.value > max) {
      return false;
    }
    if ((node.left && node.left.value > node.value) || (node.right && node.right.value < node.value)) {
      queue.push([node.right, false]);
    }
    if ((node.left && node.left.value < node.value) || (node.right && node.right.value > node.value)) {
      queue.push([node.left, false]);
    }
  }
  return true;
}

Please note that this solution assumes you are using JavaScript and the `readline` function to read input from stdin. The input is a binary tree where each line is a tree node, where the left and right children are separated by a space and the node value is the first element of the line. For example, for the tree rooted at 1, the input would be `1 2 3 4 5` representing a binary tree where:
1 is the node value, 2 is its left child, 3 is its right child, and so on.