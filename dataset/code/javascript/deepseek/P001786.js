// Define the Node class
class Node {
    constructor(data, left = null, right = null) {
        this.data = data;
        this.left = left;
        this.right = right;
    }
}

// Define the BST class
class BST {
    constructor() {
        this.root = null;
    }

    // Function to insert a node
    insert(data) {
        const node = new Node(data);

        if (this.root === null) {
            this.root = node;
        } else {
            let current = this.root;
            while (current) {
                if (node.data < current.data) {
                    if (!current.left) {
                        current.left = node;
                        break;
                    }
                    current = current.left;
                } else if (node.data > current.data) {
                    if (!current.right) {
                        current.right = node;
                        break;
                    }
                    current = current.right;
                } else {
                    break;
                }
            }
        }
    }

    // Function to search a node
    search(data) {
        let current = this.root;
        while (current) {
            if (data < current.data) {
                current = current.left;
            } else if (data > current.data) {
                current = current.right;
            } else {
                return true; // Key exists in the BST
            }
        }
        return false; // Key does not exist in the BST
    }
}

// Function to handle input and output
function handleInput(input) {
    const [n, lines] = input.split('\n').map(x => parseInt(x));

    // Create BST
    const bst = new BST();

    // Insert nodes into BST
    for (let i = 0; i < n; i++) {
        bst.insert(lines[i]);
    }

    // Search for a key
    const key = lines[n];
    console.log(bst.search(key) ? 'YES' : 'NO');
}

This script will take the input from the standard input, parse it, and then call the `handleInput` function to process the input and print the result. The `handleInput` function first splits the input by newline characters, takes the first item (the number of nodes), and uses the remaining items to create a Binary Search Tree. It then searches for the key in the BST and prints 'YES' if the key exists, and 'NO' otherwise.