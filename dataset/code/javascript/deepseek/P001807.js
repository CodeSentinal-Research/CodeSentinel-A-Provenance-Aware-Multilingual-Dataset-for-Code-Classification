Here is a JavaScript solution for the problem:

function Node(data) {
    this.data = data;
    this.left = null;
    this.right = null;
}

function BinarySearchTree() {
    this.root = null;
}

BinarySearchTree.prototype.insert = function(data) {
    var newNode = new Node(data);
    if (this.root === null) {
        this.root = newNode;
    } else {
        this.insertNode(this.root, newNode);
    }
};

BinarySearchTree.prototype.insertNode = function(node, newNode) {
    if (newNode.data < node.data) {
        if (node.left === null) {
            node.left = newNode;
        } else {
            this.insertNode(node.left, newNode);
        }
    } else {
        if (node.right === null) {
            node.right = newNode;
        } else {
            this.insertNode(node.right, newNode);
        }
    }
};

BinarySearchTree.prototype.split = function(root, data) {
    if (root === null) {
        return null;
    }

    var leftTree = new BinarySearchTree();
    var rightTree = new BinarySearchTree();

    if (root.data <= data) {
        rightTree.root = root;
        rightTree.root.right = null;
        leftTree.root = this.split(root.right, data);
    } else {
        leftTree.root = root;
        leftTree.root.left = null;
        rightTree.root = this.split(root.left, data);
    }

    return { leftTree, rightTree };
};

let bst = new BinarySearchTree();
let input = process.argv.slice(2);
input[0] = parseInt(input[0], 10);
input.splice(1, 0, parseInt(input[0], 10));

for (let i = 1; i < input.length; i++) {
    bst.insert(input[i]);
}

input[0] = parseInt(input[0], 10);
let result = bst.split(bst.root, input[0]);

console.log(JSON.stringify(result.leftTree, null, 2));
console.log(JSON.stringify(result.rightTree, null, 2));

This JavaScript program first defines the Binary Search Tree (BST) data structure and its operations. Then, it reads the data from the command line arguments, splits the BST by the given key, and prints the two resulting BSTs.