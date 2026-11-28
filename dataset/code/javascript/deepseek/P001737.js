Here is a JavaScript solution for the problem. This solution involves using Depth-First Search (DFS) to traverse the tree and find the largest perfect subtree. The solution works as follows:

1. Define a node class for the tree.
2. Initialize a variable to keep track of the maximum size of the largest perfect subtree.
3. Implement a function to perform DFS on the tree.
4. In the DFS function, for each node, calculate the size of its left and right subtree and check if they are perfect. If they are, update the maximum size if the current size is larger than the maximum size.
5. Return the maximum size.

class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

let maxSize = 0;

function dfs(node) {
    if (!node) {
        return 0;
    }

    let leftSize = dfs(node.left);
    let rightSize = dfs(node.right);

    if (leftSize !== -1 && rightSize !== -1 && leftSize + rightSize + 1 > maxSize) {
        maxSize = leftSize + rightSize + 1;
    }

    if (leftSize !== -1 && rightSize !== -1) {
        return leftSize + rightSize + 1;
    }

    return -1;
}

function largestPerfectSubtree(root) {
    maxSize = 0;
    dfs(root);
    return maxSize;
}

This solution assumes that the input is a list of nodes, where the first element in the list is the root of the tree, and the rest of the list represents the children of each node. For example, if we have the following input:

let root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);
root.right.left = new Node(6);
root.right.right = new Node(7);

The `largestPerfectSubtree` function can be called with the root of the tree as argument, and it will return the size of the largest perfect subtree.