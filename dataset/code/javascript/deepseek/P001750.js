Here is a JavaScript solution using Breadth-First Search (BFS) algorithm to find the level with the minimum number of nodes. The code first creates a binary tree from the input, then uses BFS to find the level with the minimum number of nodes.

class TreeNode {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

class BinaryTree {
    constructor() {
        this.root = null;
    }

    createTree(arr) {
        if (arr[0] === 'X') {
            this.root = null;
            return;
        }
        this.root = new TreeNode(arr[0]);
        let queue = [this.root];
        let index = 1;
        while (queue.length !== 0 && index < arr.length) {
            let current = queue.shift();
            if (arr[index] !== 'X') {
                current.left = new TreeNode(arr[index]);
                queue.push(current.left);
            }
            index++;
            if (arr[index] !== 'X') {
                current.right = new TreeNode(arr[index]);
                queue.push(current.right);
           
            }
            index++;
        }
    }

    minLevel() {
        if (this.root === null) {
            return 0;
        }

        let queue = [this.root];
        let levels = {1: [this.root]};
        while (queue.length !== 0) {
            let currentLevel = queue.length;
            for (let i = 0; i < currentLevel; i++) {
                let current = queue.shift();
                if (current.left !== null) {
                    queue.push(current.left);
                    if (!(currentLevel in levels)) {
                        levels[currentLevel] = [];
                    }
                    levels[currentLevel].push(current.left);
                }
                if (current.right !== null) {
                    queue.push(current.right);
                    if (!(currentLevel in levels)) {
                        levels[currentLevel] = [];
                    }
                    levels[currentLevel].push(current.right);
                }
            }
        }

        let minLevel = Object.keys(levels)[0];
        for (let key in levels) {
            if (levels[key].length < levels[minLevel].length) {
                minLevel = key;
            }
        }

        return minLevel;
    }
}

let input = require('fs').readFileSync('stdin', 'utf8');
let lines = input.split('\n');
let [n] = lines[0].split(' ');
let arr = lines[1].split(' ');
let binaryTree = new BinaryTree();
binaryTree.createTree(arr);
console.log(binaryTree.minLevel());
This code reads an input where the first line is the number of nodes in the tree, followed by the values of the tree nodes. It creates a binary tree from these values and then uses BFS to find the level with the minimum number of nodes.