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

    add(data) {
        const node = new Node(data);
        if (!this.root) this.root = node;
        else this._add(this.root, node);
    }

    _add(node, newNode) {
        if (newNode.data < node.data) {
            if (node.left) this._add(node.left, newNode);
            else node.left = newNode;
        } else {
            if (node.right) this._add(node.right, newNode);
            else node.right = newNode;
        }
    }

    printLeaves() {
        this._printLeaves(this.root);
    }

    _printLeaves(node) {
        if (node) {
            this._printLeaves(node.left);
            this._printLeaves(node.right);
            if (!node.left && !node.right) console.log(node.data);
        }
    }
}

let tree = new BinaryTree();

let inputs = [1, 2, 3, 4, 5];

for (let i = 0; i < inputs.length; i++) {
    tree.add(inputs[i]);
}

tree.printLeaves();

This code first creates a binary tree using the BinaryTree class. The BinaryTree class has two methods, add and printLeaves. The add method adds nodes to the binary tree, and the printLeaves method prints the leaf nodes of the binary tree from left to right.