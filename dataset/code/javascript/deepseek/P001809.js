Sure, here's a JavaScript solution that uses recursion to solve the problem. 

In this solution, we define a Node class to represent each node in the BST. Each Node has a value, left and right pointer to the left and right child nodes, and a variable 'updated' to keep track of whether the node needs to be updated. 

class Node {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
        this.updated = false;
    }
}

// Function to calculate the sum of all nodes greater than or equal to this node
function greaterSum(node) {
    if (node === null) {
        return 0;
    }
    if (node.updated) {
        return node.value;
    }
    node.updated = true;
    node.value += greaterSum(node.right) + greaterSum(node.left);
    return node.value;
}

// Function to insert node into BST
function insertNode(root, value) {
    if (root === null) {
        root = new Node(value);
        return root;
    }
    if (value < root.value) {
        root.left = insertNode(root.left, value);
    } else {
        root.right = insertNode(root.right, value);
    }
    return root;
}

// Function to create BST from input
function createBST(input) {
    let root = null;
    for (let i = 0; i < input.length; i++) {
        root = insertNode(root, input[i]);
    }
    return root;
}

// Function to print BST in in-order traversal
function inOrder(root) {
    if (root === null) {
        return;
    }
    inOrder(root.left);
    if (root.updated) {
        console.log(root.value);
    } else {
        console.log(greaterSum(root));
    }
    inOrder(root.right);
}

// Driver code
let input = [5, 2, 10, 1, 7, 0, 15, 6, 8, 13];
let root = createBST(input);
inOrder(root);

This code first creates a binary search tree from the given input. It then prints out the values in the tree in in-order traversal, replacing each value with the sum of all keys greater than or equal to that node.