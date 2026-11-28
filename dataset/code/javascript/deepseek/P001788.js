Here's the code to delete a key from a Binary Search Tree (BST):

class Node {
  constructor(data, left = null, right = null) {
    this.data = data;
    this.left = left;
    this.right = right;
  }
}

class BST {
  constructor() {
    this.root = null;
  }

  insert(data) {
    const node = new Node(data);
    if (this.root === null) {
      this.root = node;
    } else {
      let current = this.root;
      while (current) {
        if (node.data < current.data) {
          if (!current.left) {
            current.left = node;
            break;
          }
          current = current.left;
        } else if (node.data > current.data) {
          if (!current.right) {
            current.right = node;
            break;
          }
          current = current.right;
        } else {
          break;
        }
      }
    }
  }

  delete(data) {
    let current = this.root;
    let parent = null;
    while (current) {
      if (data < current.data) {
        parent = current;
        current = current.left;
      } else if (data > current.data) {
        parent = current;
        current = current.right;
      } else {
        if (current.left && current.right) {
          current.data = this.getMinValue(current.right);
          this.deleteMinValue(current.right);
        } else if (parent == null) {
          if (current.left == null) {
            this.root = current.right;
          } else {
            if (current.right == null) {
              this.root = current.left;
            } else {
              current.data = this.getMinValue(current.right);
              this.deleteMinValue(current.right);
            }
          }
        } else if (parent.left == current) {
          parent.left = current.left ? current.left : current.right;
        } else {
          parent.right = current.left ? current.left : current.right;
        }
        break;
      }
    }
  }

  getMinValue(node) {
    let current = node;
    while (current.left) {
      current = current.left;
    }
    return current.data;
  }

  deleteMinValue(node) {
    if (node.left) {
      node.data = this.getMinValue(node.left);
      this.deleteMinValue(node.left);
    } else if (node.right) {
      node.data = this.getMinValue(node.right);
      this.deleteMinValue(node.right);
    } else {
      node = null;
    }
  }
}

let bst = new BST();

process.stdin.resume();
process.stdin.on('data', (chunk) => {
  let data = chunk.toString().trim().split('\n');
  let N = parseInt(data[0]);
  data.slice(1, N).forEach((d) => {
    bst.insert(d);
  });
  let K = parseInt(data[N]);
  bst.delete(K);
  process.stdout.write(JSON.stringify(bst.root) + '\n');
  process.stdin.pause();
});

This code will take as input the root of the BST, followed by the number of lines (N), each line containing the data of one node of the BST. After that, it will process K nodes to delete from the BST.

Please note that the BST is a binary search tree, and nodes must be unique. The delete method will remove the key from the BST and rearrange the rest of the tree to maintain the BST property.