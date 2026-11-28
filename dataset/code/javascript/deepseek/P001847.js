Here is a solution in JavaScript that uses the concept of In-Order Traversal to find the in-order traversal of the Binary Search Tree. This in-order traversal will give us the sorted sequence of the BST and the minimum number of rotations to make the BST balanced.

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

    add(data) {
        const node = this.root;
        if (node === null) {
            this.root = new Node(data);
            return;
        } else {
            let newNode = new Node(data);
            while (node) {
                if (data < node.data) {
                    if (node.left === null) {
                        node.left = newNode;
                        break;
                    }
                    node = node.left;
                } else if (data > node.data) {
                    if (node.right === null) {
                        node.right = newNode;
                        break;
                    }
                    node = node.right;
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
                if (this.countNodes(current.left) < this.countNodes(current.right)) {
                    let temp = current.right;
                    current.right = current.left;
                    current.left = temp;
                }
                current = current.right;
            }
            return this.root;
        }
    }

    countNodes(node) {
        if (node === null) {
            return 0;
        } else {
            let count = 1;
            count += this.countNodes(node.left);
            count += this.countNodes(node.right);
            return count;
        }
    }
}

let bst = new BST();
let n = parseInt(readline());
for (let i = 0; i < n; i++) {
    bst.add(parseInt(readline()));
}
bst.inOrder();

In this solution, we first create a BST class with methods to add nodes to the BST and to perform an in-order traversal to generate the sorted sequence of the BST. The `inOrder` method first initializes an empty stack and then repeatedly pops nodes from the stack, rotates the current node to the right if the count of nodes in the left subtree is less than the count in the right subtree, and pushes the current node back to the stack.

The `countNodes` method counts the total number of nodes in the BST by recursively counting the nodes in the left and right subtrees.

The main part of the solution is reading the input and adding nodes to the BST. After all nodes have been added, it performs an in-order traversal to generate the sorted sequence of the BST, and then prints the number of rotations needed to make the BST height-balanced.

This solution assumes that the input will be given in a format where each line contains an integer and is separated by a space. The count of nodes is taken as the length of the input.