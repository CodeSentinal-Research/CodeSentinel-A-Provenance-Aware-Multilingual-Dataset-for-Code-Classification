Here is a JavaScript solution using Depth-First Search (DFS) to create a deep copy of the binary tree. The idea is to recursively traverse the original tree and when we find a node, we create a clone of it and add it to our cloned tree. Also, we make sure to create random pointers for the clone by setting the `random` property of the clone to be a clone of the `random` pointer in the original tree.

class Node {
    constructor(x, left = null, right = null, random = null) {
        this.val = x;
        this.left = left;
        this.right = right;
        this.random = random;
    }
}

function cloneTree(root) {
    if (root === null) {
        return null;
    }

    let clone = new Node(root.val);
    clone.left = cloneTree(root.left);
    clone.right = cloneTree(root.right);
    clone.random = cloneTree(root.random);

    return clone;
}

let root1 = new Node(1);
root1.left = new Node(2);
root1.right = new Node(3);
root1.left.left = new Node(4);
root1.left.right = new Node(5);
root1.random = new Node(6);

let root2 = cloneTree(root1);

This code first defines a `Node` class that represents a node in the binary tree. Each node has a value, and it can have left and right children. Also, each node has a `random` pointer that points to another node in the tree.

Then, we define a `cloneTree` function that takes a root node of the binary tree and returns a clone of the tree. The function works by first checking if the root node is `null`. If it is, the function returns `null`. Otherwise, it creates a new node with the same value as the root node, and then recursively calls the `cloneTree` function on the left and right children.

Finally, we create a binary tree, clone it, and print the cloned tree.