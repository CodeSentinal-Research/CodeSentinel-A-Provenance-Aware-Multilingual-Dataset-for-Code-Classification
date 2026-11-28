Here is a basic JavaScript solution for the problem. This solution uses an in-order traversal of the Binary Search Tree (BST) and constructs the lexicographically smallest insertion sequence.

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
            let current = this.root;
            while (current) {
                if (data < current.data) {
                    if (!current.left) {
                        current.left = newNode;
                        break;
                    }
                    current = current.left;
                } else if (data > current.data) {
                    if (!current.right) {
                        current.right = newNode;
                        break;
                    }
                    current = current.right;
                } else {
                    break;
                }
            }
        }
    }

    inOrder() {
        if (this.root === null) {
            return null;
        } else {
            let current = this.root;
            let stack = [];
            while (current || stack.length) {
                while (current) {
                    stack.push(current);
                    current = current.left;
                }
                current = stack.pop();
                console.log(current.data);
                current = current.right;
            }
        }
    }
}

let input = process.argv[2];
let n = parseInt(input[0]);

let bst = new BST();

for (let i = 3; i < input.length; i += 2) {
    bst.insert(parseInt(input[i]));
}

bst.inOrder();

In this code, we first create a Node class for the nodes of the BST. Each Node has a data value, and a left and right pointer.

The BST class has an insert method to add new nodes to the BST. The insert method follows the BST rule of insertion (each node to the left of a parent node has a value less than the parent node, and each node to the right has a value greater). If the new node is the same as the parent node, it is not added to the tree.

The inOrder method traverses the BST in in-order (left-root-right) order. It uses a stack to keep track of the current node and its descendants. It starts at the root, and for each node, it pushes it to the stack, then goes left, and finally goes right.

The script reads the number of nodes from the first argument, and then the nodes themselves from the rest of the arguments. The script then inserts each node into the BST, and finally in-orders the BST to print the lexicographically smallest insertion sequence.