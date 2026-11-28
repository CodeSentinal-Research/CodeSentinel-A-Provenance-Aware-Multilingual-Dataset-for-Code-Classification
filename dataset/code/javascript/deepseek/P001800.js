Here is the JavaScript code for the problem:

function Node(data) {
    this.data = data;
    this.left = null;
    this.right = null;
}

function insert(root, node) {
    if (root === null) {
        root = node;
    } else {
        if (node.data < root.data) {
            if (root.left === null) {
                root.left = node;
            } else {
                insert(root.left, node);
            }
        } else {
            if (root.right === null) {
                root.right = node;
            } else {
                insert(root.right, node);
            }
        }
    }
}

function recoverTree(data) {
    let root = null;
    for (let i = 0; i < data.length; i++) {
        insert(root, new Node(data[i]));
    }
    return root;
}

let N = parseInt(readline());
let data = readline().split(' ').map(Number);
while (data.length) {
    let root = recoverTree(data);
    console.log(JSON.stringify(root, null, 2));
    data = readline().split(' ').map(Number);
}

This code first defines a Node constructor for creating new nodes in the BST. Then, it defines an insert function that adds new nodes to the BST recursively. The recoverTree function uses the insert function to build the BST from the given data.

Next, it reads the input and creates a new BST for each set of data. It then logs the BST to the console, and reads the next set of data.

Please note that the `readline` function is a placeholder for a function that reads input from the console, you should replace it with the actual function that reads the input from the console.