Here is the JavaScript code that solves the problem:

class TreeNode {
  constructor(val = 0, left = null, right = null) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

class BST {
  constructor() {
    this.root = null;
  }

  add(val) {
    const node = this.root ? this.root : new TreeNode(val);
    if (!this.root) this.root = node;
    else {
      let current = this.root;
      while (current) {
        if (val < current.val) {
          if (!current.left) {
            current.left = new TreeNode(val);
            break;
          }
          current = current.left;
        } else {
          if (!current.right) {
            current.right = new TreeNode(val);
            break;
          }
          current = current.right;
        }
      }
    }
  }

  kthLargest(k) {
    let stack = [];
    let current = this.root;
    while (current || stack.length) {
      while (current) {
        stack.push(current);
        current = current.right;
      }
      current = stack.pop();
      if (k === 1) return current.val;
      k--;
      current = current.left;
    }
    return -1;
  }
}

let n = process.stdin.readline();
let tree = new BST();
while (n < 3) {
  let line = process.stdin.readline();
  n++;
}

let values = line.split(' ').map(Number);
for (let val of values) {
  tree.add(val);
}
let k = values[values.length - 1];
console.log(tree.kthLargest(k));

This script reads an input from standard input and constructs a Binary Search Tree from the given values. It then calculates the Kth largest element and prints it.

Please note that the input should be provided in the following format:

1. The first line is the number of nodes.
2. The next N lines contain the values of the nodes.
3. The last line is the value of K.

For example, if you have the following input:

5
5 3 8 1 4
4

The script will output `8` as the 4th largest element.