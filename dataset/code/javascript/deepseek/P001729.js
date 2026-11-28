Sure, here is a simple JavaScript code to solve the problem:

class Node {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

class BinaryTree {
  constructor() {
    this.root = null;
  }

  buildTree(nodes, x, y, parent, dir) {
    if (x < nodes.length) {
      let temp = new Node(nodes[x]);
      this.root = temp;
      if (parent === 'left')
        parent.left = temp;
      else
        parent.right = temp;
      this.buildTree(nodes, x * 2 + 1, y, temp, 'left');
      this.buildTree(nodes, x * 2 + 2, y, temp, 'right');
    }
  }

  findDistance(node1, node2, k) {
    let d1 = this.findLevel(node1, node2, k);
    let d2 = this.findLevel(node2, node1, k);
    return (d1 + d2);
  }

  findLevel(parent, child, k) {
    if (parent === null)
      return -1;
    let dl = 0;
    if (parent.data === child.data)
      return dl;
    let dr = this.findLevel(parent.right, child, k);
    let dl = this.findLevel(parent.left, child, k);
    if (dr >= 0 && dl >= 0)
      return dl + dr + 1;
    if (dr >= 0)
      return dr + 1;
    if (dl >= 0)
      return dl + 1;
    return -1;
  }
}

let btree = new BinaryTree();
let nodes = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20];
btree.buildTree(nodes, 0, 0, null, null);
console.log(btree.findDistance(btree.root, nodes[10], 2));

In the above code, we are building a binary tree using the given nodes. We are also finding the distance between two nodes. The findDistance function finds the distance between two nodes using the findLevel function. The findLevel function calculates the distance from the parent to the child.