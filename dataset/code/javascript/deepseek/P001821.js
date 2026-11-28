Here is the code:

function Node(value) {
  this.value = value;
  this.left = null;
  this.right = null;
}

function insertNode(root, value) {
  if (root === null) {
    root = new Node(value);
  } else if (value < root.value) {
    root.left = insertNode(root.left, value);
  } else {
    root.right = insertNode(root.right, value);
  }
  return root;
}

function preorder(root) {
  if (root !== null) {
    console.log(root.value);
    preorder(root.left);
    preorder(root.right);
  }
}

function inorder(root) {
  if (root !== null) {
    inorder(root.left);
    console.log(root.value);
    inorder(root.right);
  }
}

function postorder(root) {
  if (root !== null) {
    postorder(root.left);
    postorder(root.right);
    console.log(root.value);
  }
}

function buildMinHeap(root) {
  if (root === null) {
    return null;
  }
  buildMinHeap(root.left);
  buildMinHeap(root.right);

  if (root.left) {
    if (root.left.value > root.value) {
      let temp = root.left.value;
      root.left.value = root.value;
      root.value = temp;
    }
  } else if (root.right) {
    if (root.right.value < root.value) {
      let temp = root.right.value;
      root.right.value = root.value;
      root.value = temp;
    }
  }
  return root;
}

// Input:
// 5
// 2
// 1 3
// 5 6
// 2 4
// 1 5 6

let root = null;
let lines = process.stdin.readLines();
let count = parseInt(lines.next());

for (let i = 0; i < count; i++) {
  let line = lines.next();
  let values = line.split(' ');
  root = insertNode(root, parseInt(values[0]));
  if (values[1]) {
    root = insertNode(root, parseInt(values[1]));
  }
  if (values[2]) {
    root = insertNode(root, parseInt(values[2]));
  }
}

let minHeapRoot = buildMinHeap(root);
postorder(minHeapRoot);

Please note that this solution assumes you are using Node.js and the `readLines` function from `readline` module. It reads the input from standard input. You can run this solution from your local environment by providing the input manually or you can use an online JavaScript compiler to run the code.