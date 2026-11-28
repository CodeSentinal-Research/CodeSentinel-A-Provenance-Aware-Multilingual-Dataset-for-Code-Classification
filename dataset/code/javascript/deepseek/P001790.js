Sure, here is the JavaScript code to find the minimum value in a Binary Search Tree (BST):

// Node definition
class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

// BST definition
class BST {
    constructor() {
        this.root = null;
    }

    // Insertion method
    insert(data) {
        const newNode = new Node(data);
        if (this.root === null) {
            this.root = newNode;
        } else {
            let current = this.root;
            while (current) {
                if (newNode.data < current.data) {
                    if (current.left === null) {
                        current.left = newNode;
                        return;
                    }
                    current = current.left;
                } else {
                    if (current.right === null) {
                        current.right = newNode;
                        return;
                    }
                    current = current.right;
                }
            }
        }
    }

    // Function to find minimum value in BST
    findMin() {
        if (this.root === null) {
            return null;
        } else {
            let current = this.root;
            while (current.left) {
                current = current.left;
            }
            return current.data;
        }
    }
}

// Driver code
let bst = new BST();
let inputs = [];
process.stdin.resume();
process.stdin.setEncoding('ascii');

process.stdin.on('data', (input) => {
    inputs.push(input);
});

process.stdin.on('end', () => {
    let N = parseInt(inputs[0]);

    for (let i = 1; i <= N; i++) {
        let data = parseInt(inputs[i]);
        bst.insert(data);
    }

    console.log(bst.findMin());
});

In this code, we first define a node and a binary search tree. The binary search tree is a tree in which all the nodes in the left subtree are smaller than the root and all the nodes in the right subtree are larger than the root.

In the BST class, we have an insert method where we insert new nodes into the binary search tree. We do this by starting from the root, and for each new node, we compare it to the current node. If the new node's data is less than the current node's data, we move to the left child of the current node. If the new node's data is greater than the current node's data, we move to the right child of the current node. If the new node's data is less than or equal to the current node's data, we move to the left child of the current node (if it exists). If the new node's data is greater than or equal to the current node's data, we move to the right child of the current node (if it exists). This process is repeated until we find an empty spot for the new node.

Finally, in the findMin method, we start from the root, and move to the leftmost node in the left subtree, because the minimum value in a BST is always less than its leftmost node.