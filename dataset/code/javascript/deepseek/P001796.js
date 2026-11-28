Here is the JavaScript code to construct a Binary Search Tree from its Preorder Traversal:

class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

function constructBST(preorder) {
    if (preorder.length === 0) {
        return null;
    }

    let root = new Node(preorder[0]);
    let stack = [root];

    for (let i = 1; i < preorder.length; i++) {
        while (stack[stack.length - 1] !== preorder[i]) {
            let parent = stack.pop();
            let newNode = new Node(preorder[i]);
            if (parent.data > preorder[i]) {
                parent.left = newNode;
            } else {
                parent.right = newNode;
            }
        }
    }

    return root;
}

function preOrder(node) {
    if (node === null) {
        return;
    }
    console.log(node.data);
    preOrder(node.left);
    preOrder(node.right);
}

let preorder = [10, 5, 15, 1, 7, 13];
let root = constructBST(preorder);
preOrder(root);

This code creates a binary search tree (BST) using the preorder traversal of the given array. The preorder traversal is a method of traversing or storing a tree data. This is done by first traversing the left subtree, then the right subtree and then the root.

In the constructBST function, for each key in the preorder traversal, we are making a new Node with that value. Then we push the root node to the stack and start iterating over the remaining keys in the preorder traversal. If the top of the stack is not equal to the current key, we pop it from the stack and make it as the right child of the popped node, otherwise we make it as the left child.

The preOrder function is used to print the preorder traversal of the BST.