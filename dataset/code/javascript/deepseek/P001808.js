Here is a simple JavaScript solution that uses recursive method to merge two Binary Search Trees:

class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

function sortedArrayToBST(arr) {
    if (!arr.length) return null;

    let mid = Math.floor(arr.length / 2);
    let root = new Node(arr[mid]);

    let left = sortedArrayToBST(arr.slice(0, mid));
    let right = sortedArrayToBST(arr.slice(mid + 1));

    root.left = left;
    root.right = right;

    return root;
}

function mergeBSTs(root1, root2) {
    let arr1 = [];
    inorder(root1, arr1);

    let arr2 = [];
    inorder(root2, arr2);

    let mergedArr = arr1.concat(arr2);

    mergedArr.sort((a, b) => a - b);

    return sortedArrayToBST(mergedArr);
}

function inorder(root, arr) {
    if (root) {
        inorder(root.left, arr);
        arr.push(root.data);
        inorder(root.right, arr);
    }
}

// Test the solution
let root1 = new Node(5);
root1.left = new Node(3);
root1.right = new Node(7);
root1.left.left = new Node(2);
root1.left.right = new Node(4);
root1.right.left = new Node(6);
root1.right.right = new Node(8);

let root2 = new Node(10);
root2.left = new Node(9);
root2.right = new Node(11);
root2.left.left = new Node(1);
root2.left.right = new Node(8);
root2.right.left = new Node(12);
root2.right.right = new Node(15);

let root = mergeBSTs(root1, root2);

// Print the merged tree
function printTree(root) {
    if (root) {
        printTree(root.left);
        console.log(root.data);
        printTree(root.right);
    }
}

printTree(root);

This code first defines a `Node` class for a node in the binary search tree. The `sortedArrayToBST` function is used to convert a sorted array into a binary search tree. The `mergeBSTs` function takes two binary search trees as inputs and merges them into a single binary search tree. The `inorder` function is used to traverse the tree in inorder (left-root-right) order and store the values in an array. The `mergeBSTs` function uses these functions to merge the two binary search trees. Finally, the `printTree` function is used to print the merged binary search tree.