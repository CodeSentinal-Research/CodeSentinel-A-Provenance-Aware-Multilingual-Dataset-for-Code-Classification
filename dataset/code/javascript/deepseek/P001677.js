function findCousins(root, target) {
  let queue = [root];
  let cousinNodes = [];
  while (queue.length) {
    let levelNodes = [];
    for (let i = 0; i < queue.length; i++) {
      let node = queue.shift();
      if (node.left) {
        queue.push(node.left);
        levelNodes.push(node.left);
      }
      if (node.right) {
        queue.push(node.right);
        levelNodes.push(node.right);
      }
    }
    if (levelNodes.includes(target)) {
      cousinNodes = levelNodes.filter(node => node.parent !== target.parent);
    }
    levelNodes = [];
  }
  cousinNodes.length ? console.log(cousinNodes.map(node => node.val)) : console.log('NONE');
}

class TreeNode {
  constructor(val, left = null, right = null, parent = null) {
    this.val = val;
    this.left = left;
    this.right = right;
    this.parent = parent;
  }
}

// Test
let root = new TreeNode(1);
root.left = new TreeNode(2);
root.right = new TreeNode(3);
root.left.left = new TreeNode(4);
root.left.right = new TreeNode(5);
root.right.left = new TreeNode(6);
root.right.right = new TreeNode(7);
findCousins(root, root.left.right); // Output: 4, 5