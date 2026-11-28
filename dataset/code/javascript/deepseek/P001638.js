Here is the JavaScript code for the problem:

class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

function mirror(root) {
    if (root == null) {
        return null;
    }

    let temp = root.left;
    root.left = mirror(root.right);
    root.right = mirror(temp);

    return root;
}

function createMirrorTree(arr) {
    let root = new Node(arr[0]);
    let currentNode = root;

    for(let i = 1; i < arr.length; i++){
        let node = new Node(arr[i]);
        currentNode.right = node;
        currentNode = node;
    }

    return mirror(root);
}

// Testing the solution
let arr = [1,2,3,4,5,6,7];
console.log(createMirrorTree(arr));
This program first creates a binary tree with the given array of values. Then it calls the `mirror` function, which recursively swaps the left and right children of each node in the tree. Finally, it prints the mirrored tree.