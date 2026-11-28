function Node(data, left = null, right = null) {
    this.data = data;
    this.left = left;
    this.right = right;
}

function BinaryTree(root) {
    this.root = root;
}

BinaryTree.prototype.getHeight = function() {
    let height = 0;
    function helper(node, height) {
        if (!node) {
            return height;
        }
        height++;
        return Math.max(helper(node.left, height), helper(node.right, height));
    }
    return helper(this.root, height);
}