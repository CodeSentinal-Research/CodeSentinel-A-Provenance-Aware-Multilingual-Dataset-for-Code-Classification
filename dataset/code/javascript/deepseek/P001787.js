Here is the JavaScript code to insert a key into a binary search tree:

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
        const node = this.root;
        if (node === null) {
            this.root = new Node(data);
            return;
        } else {
            const searchTree = function(node) {
                if (data < node.data) {
                    if (node.left === null) {
                        node.left = new Node(data);
                        return;
                    } else if (node.left !== null) {
                        return searchTree(node.left);
                    }
                } else if (data > node.data) {
                    if (node.right === null) {
                        node.right = new Node(data);
                        return;
                    } else if (node.right !== null) {
                        return searchTree(node.right);
                    }
                } else {
                    return null;
                }
            };
            return searchTree(node);
        }
    }

    minValueNode(node) {
        let current = node;

        while (current.left !== null) {
            current = current.left;
        }

        return current;
    }

    deleteNode(root, key) {
        //...
    }

    //...
}

// Sample usage
const input = [5, 3, 7, 2, 4, 6, 8];
const bst = new BST();

input.forEach(data => {
    bst.insert(data);
});

This code defines a BST class with methods for insertion, deletion, and other operations. The BST class is initialized with a root node. The insert method is used to add a new key to the BST. If the BST is empty, the new key becomes the root. If the BST is not empty, the new key is inserted in the correct position in the BST.

The minValueNode method is used to find the node with the smallest key in the BST.

Please note that this is a simple example and does not include all the methods you might need for a complete BST implementation.