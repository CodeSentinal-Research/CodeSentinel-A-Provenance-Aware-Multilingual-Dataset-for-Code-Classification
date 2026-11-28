Here is a JavaScript solution for the problem.

// Define a TreeNode
class TreeNode {
    constructor(data, left = null, right = null) {
        this.data = data;
        this.left = left;
        this.right = right;
    }
}

// Define a Function to Build the Tree
function constructTree(nodes, start) {
    if (start >= nodes.length || nodes[start] === null) {
        return null;
    }

    var root = new TreeNode(nodes[start]);
    root.left = constructTree(nodes, 2 * start + 1);
    root.right = constructTree(nodes, 2 * start + 2);
    return root;
}

// Define a Function to Convert the Tree to Sum Tree
function convertTreeToSumTree(root) {
    if (root === null) {
        return 0;
    }

    var leftSum = convertTreeToSumTree(root.left);
    var rightSum = convertTreeToSumTree(root.right);

    var sum = root.data + leftSum + rightSum;
    root.data = sum;
    return sum;
}

// Define a Function to Print the Tree
function printTree(root) {
    if (root === null) {
        return;
    }

    console.log(root.data);
    printTree(root.left);
    printTree(root.right);
}

// Driver Code
var input = [5, 2, 6, 1, 3, null, 1, null, null, null, 2, null, 1, null, null, 1];
var tree = constructTree(input, 0);
convertTreeToSumTree(tree);
printTree(tree);

This code first constructs a binary tree from the given input. Then it converts this tree to a sum tree. The `convertTreeToSumTree` function goes through each node in the tree and updates the value of the node. Finally, the `printTree` function is used to print the transformed tree.