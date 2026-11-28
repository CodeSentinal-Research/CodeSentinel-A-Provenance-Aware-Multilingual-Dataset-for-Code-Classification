Here is the JavaScript code for the problem:

// define the binary search tree
class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

// function to create binary search tree
function createBST(arr, root = null, i = 0) {
    if (root === null) {
        root = new Node(arr[i]);
        i++;
    } else {
        if (arr[i] < root.data) {
            if (root.left === null) {
                root.left = new Node(arr[i]);
            } else {
                createBST(arr, root.left, i);
            }
        } else {
            if (root.right === null) {
                root.right = new Node(arr[i]);
            } else {
                createBST(arr, root.right, i);
            }
        }
    }

    return root;
}

// function to find the lowest common ancestor
function findLowestCommonAncestor(root, key1, key2) {
    if (root === null) {
        return null;
    }

    if (root.data > key1 && root.data > key2) {
        return findLowestCommonAncestor(root.left, key1, key2);
    }

    if (root.data < key1 && root.data < key2) {
        return findLowestCommonAncestor(root.right, key1, key2);
    }

    return root;
}

// create the binary search tree
let arr = [20, 8, 22, 4, 12, 10, 14];
let root = createBST(arr);

// find the lowest common ancestor
let key1 = 10;
let key2 = 14;
console.log(findLowestCommonAncestor(root, key1, key2).data);

This code first creates a binary search tree from an array. The binary search tree is a binary tree where all the nodes to the left of a node are smaller than the node, and all the nodes to the right are larger than the node. The lowest common ancestor of two nodes in a binary search tree is the node that is the greatest common ancestor of the two nodes.

Then, it finds the lowest common ancestor of two given keys in the binary search tree and prints the value of the lowest common ancestor.

The input to this code is an array where each element represents a node in the binary search tree. The first element in the array represents the root of the binary search tree. The remaining elements represent the nodes of the binary search tree. The last two elements are the two keys that we want to find their lowest common ancestor.