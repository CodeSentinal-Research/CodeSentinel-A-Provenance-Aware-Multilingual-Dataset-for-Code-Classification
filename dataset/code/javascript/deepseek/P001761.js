let cache = new Map();

class TreeNode {
    constructor(val = 0, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class BinaryTree {
    constructor(root) {
        this.root = root;
    }
    
    findMaxSum(node) {
        if (!node) {
            return 0;
        }
        if (node.val + this.findMaxSum(node.left) + this.findMaxSum(node.right) > 0) {
            return node.val + this.findMaxSum(node.left) + this.findMaxSum(node.right);
        }
        return 0;
    }
    
    solve() {
        this.maxSum = -Infinity;
        this.maxNode = null;
        this.findMaxSum(this.root);
        return this.maxNode.val;
    }
}

// Read input
let n = parseInt(readline());
let nodes = readline().split(' ').map(Number);
let tree = new BinaryTree(new TreeNode(nodes[0]));
let head = tree.root;
for (let i = 1; i < n; i++) {
    let parent = nodes[i - 1];
    let node = new TreeNode(nodes[i]);
    if (parent * 2 + 1 < n) {
        tree.root.left = node;
    } else {
        tree.root.right = node;
    }
    if (cache.has(parent)) {
        node.left = cache.get(parent);
        cache.set(parent, node);
    } else {
        let left = nodes[2 * parent + 1] != -1 ? new TreeNode(nodes[2 * parent + 1]) : null;
        node.left = left;
    }
    if (2 * parent + 2 < n) {
        let right = new TreeNode(nodes[2 * parent + 2]);
        node.right = right;
    }
}
console.log(tree.solve());