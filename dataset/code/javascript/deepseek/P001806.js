Here is the JavaScript code for the problem:

let arr = []
let idx = 0

function constructBST(arr, start, end, node) {
    if(node === null) return
    if(start <= node.val && node.val <= end) {
        arr[idx++] = node.val
        constructBST(arr, start, node.val - 1, node.left)
        constructBST(arr, node.val + 1, end, node.right)
    } else if(node.val > end) {
        constructBST(arr, start, node.val - 1, node.left)
    } else {
        constructBST(arr, node.val + 1, end, node.right)
    }
}

function solve(arr, L, R) {
    let root = null
    arr.sort((a, b) => a - b)
    constructBST(arr, 0, arr[arr.length - 1], root)
    return root
}

function printTree(root) {
    if(root === null) return
    printTree(root.left)
    console.log(root.val)
    printTree(root.right)
}

This code constructs a Binary Search Tree from an array of integers. The solve function is then used to construct the BST with the given range. The printTree function is used to print the resulting BST. The constructBST function is a recursive function that constructs the BST. It sorts the array first, then recursively calls itself on the two sides of the current node based on whether their values are within the given range.