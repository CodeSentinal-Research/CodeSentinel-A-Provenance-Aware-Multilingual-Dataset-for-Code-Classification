function Node(data) {
  this.data = data;
  this.left = null;
  this.right = null;
}

function diameterOfBinaryTree(root) {
  if(root === null) {
    return 0;
  }
  let lheight = height(root.left);
  let rheight = height(root.right);

  let ldiameter = diameterOfBinaryTree(root.left);
  let rdiameter = diameterOfBinaryTree(root.right);

  return Math.max(lheight + rheight + 1, Math.max(ldiameter, rdiameter));
}

function height(root) {
  if(root === null) {
    return 0;
  }
  return 1 + Math.max(height(root.left), height(root.right));
}