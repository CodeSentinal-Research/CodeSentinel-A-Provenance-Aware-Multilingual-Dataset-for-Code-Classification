Here is a JavaScript solution using recursive approach:

class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class BST {
    constructor() {
        this.root = null;
    }

    insert(data) {
        let newNode = new Node(data);
        if (this.root === null) {
            this.root = newNode;
        } else {
            this.insertNode(this.root, newNode);
        }
    }

    insertNode(node, newNode) {
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
    }

    findMinValueNode(node) {
        let current = node;
        while (current.left !== null) {
            current = current.left;
        }
        return current;
    }

    deleteNode(root, key) {
        if (root === null) {
            return root;
        }
        if (key < root.data) {
            root.left = this.deleteNode(root.left, key);
        } else if (key > root.data) {
            root.right = this.deleteNode(root.right, key);
        } else {
            if (root.left === null) {
                return root.right;
            } else if (root.right === null) {
                return root.left;
            }
            let temp = this.findMinValueNode(root.right);
            root.data = temp.data;
            root.right = this.deleteNode(root.right, temp.data);
        }
        return root;
    }

    findInorderSuccessor(root, key) {
        if (root === null) {
            return null;
        }
        if (root.left !== null && root.left.data === key) {
            return this.findMinValueNode(root.right);
        }
        if (root.data > key) {
            return root;
        }
        let resultNode;
        if (root.right !== null) {
            resultNode = this.findMinValueNode(root.right);
        } else if (root.left !== null) {
            resultNode = this.findMinValueNode(root.left);
        }
        return resultNode;
    }
}

let N = parseInt(readline());
let bst = new BST();
for (let i = 0; i < N; i++) {
    let data = parseInt(readline());
    bst.insert(data);
}
let key = parseInt(readline());
let inorderSuccessor = bst.findInorderSuccessor(bst.root, key);
if (inorderSuccessor === null) {
    console.log("None");
} else {
    console.log(inorderSuccessor.data);
}

In this code, we first define a Node class and a BST class. The BST class has methods to insert a node, delete a node, find the minimum value node, and find the inorder successor of a given node.

We then read the number of nodes and the nodes themselves, and insert them into the BST. Finally, we read the target node and print its inorder successor. If the inorder successor does not exist, we print "None".