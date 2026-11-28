function Node(data, left = null, right = null) {
    this.data = data;
    this.left = left;
    this.right = right;
}

function BST(root = null) {
    this.root = root;
}

BST.prototype.addNode = function(data) {
    let node = new Node(data);

    if (!this.root) {
        this.root = node;
    } else {
        this.insertNode(this.root, node);
    }
};

BST.prototype.insertNode = function(node, newNode) {
    if (newNode.data < node.data) {
        if (node.left) {
            this.insertNode(node.left, newNode);
        } else {
            node.left = newNode;
        }
    } else {
        if (node.right) {
            this.insertNode(node.right, newNode);
        } else {
            node.right = newNode;
        }
    }
};

BST.prototype.findKthSmallest = function(k) {
    return this.findKthSmallestNode(this.root, k);
};

BST.prototype.findKthSmallestNode = function(node, k) {
    if (node === null) {
        return null;
    }

    let leftSize = this.getSize(node.left);

    if (leftSize + 1 === k) {
        return node;
    }
    if (leftSize + 1 < k) {
        return this.findKthSmallestNode(node.right, k - leftSize - 1);
    }
    if (leftSize + 1 > k) {
        return this.findKthSmallestNode(node.left, k);
    }
};

BST.prototype.getSize = function(node) {
    if (node === null) {
        return 0;
    }
    return 1 + this.getSize(node.left) + this.getSize(node.right);
};

let root = null;
let bst = new BST(root);

function solve() {
    let n = parseInt(readLine());
    for (let i = 0; i < n; i++) {
        let [data, left, right] = readLine().split(' ');
        bst.addNode(parseInt(data));
        if (left !== 'null') {
            bst.addNode(parseInt(left));
        }
        if (right !== 'null') {
            bst.addNode(parseInt(right));
        }
    }
    let k = parseInt(readLine());
    console.log(bst.findKthSmallest(k));
}

solve();