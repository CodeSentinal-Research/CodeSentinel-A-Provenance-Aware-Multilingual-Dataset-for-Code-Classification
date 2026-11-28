Here is the JavaScript solution for the problem:

class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class BinaryTree {
    constructor() {
        this.root = null;
    }

    findLongestPath(node) {
        if (node == null) {
            return 0;
        }
        let leftPath = this.findLongestPath(node.left);
        let rightPath = this.findLongestPath(node.right);

        let maxPath = Math.max(leftPath, rightPath);

        return maxPath + 1;
    }

    populateTree(arr, node, i) {
        if (i < arr.length) {
            if (arr[i] != null) {
                node.left = new Node(arr[i]);
                this.populateTree(arr, node.left, 2 * i + 1);
            }
            if (i < arr.length - 1) {
                node.right = new Node(arr[i + 1]);
                this.populateTree(arr, node.right, 2 * i + 2);
           
            }
        }
    }

    construct(arr) {
        this.root = new Node(arr[0]);
        this.populateTree(arr, this.root, 0);
    }

    longestPath() {
        let maxPath = this.findLongestPath(this.root);
        console.log('Longest path length is: ' + maxPath);
    }
}

let arr = [1, 2, 3, 4, 5, 6, 7];
let bt = new BinaryTree();
bt.construct(arr);
bt.longestPath();

This code first creates a Node class and a BinaryTree class. The BinaryTree class has a method to construct the binary tree from an array. It also has a method to find the longest path from the root to any leaf in the tree.

The input array is created in such a way that it matches the binary tree representation. For instance, if the array is [1, 2, 3, 4, 5, 6, 7], it matches the binary tree:

        1
       / \
      2   3
     / \ / \
    4  5 6  7

This code then constructs the binary tree and prints the longest path length.