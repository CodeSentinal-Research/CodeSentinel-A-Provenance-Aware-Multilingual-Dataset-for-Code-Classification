Here is a JavaScript solution to find the longest decreasing root-to-leaf path in a binary tree:

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

    add(data) {
        const newNode = new Node(data);

        if (this.root === null) {
            this.root = newNode;
        } else {
            this.insertNode(this.root, newNode);
        }
    }

    insertNode(node, newNode) {
        if (node.data < newNode.data) {
            if (node.right === null) {
                node.right = newNode;
            } else {
                this.insertNode(node.right, newNode);
            }
        } else {
            if (node.left === null) {
                node.left = newNode;
            } else {
                this.insertNode(node.left, newNode);
            }
        }
    }

    longestDeccPath(node) {
        if (node === null) {
            return 0;
        }

        // get the height of the left and right subtrees
        let lheight = this.longestDeccPath(node.left);
        let rheight = this.longestDeccPath(node.right);

        // get the height of the left and right subtrees plus the current node
        let height = lheight > rheight ? lheight + 1 : rheight + 1;

        // get the maximum of the two heights
        return height;
    }

    printPaths(node) {
        let paths = [];
        this.getPaths(node, [], paths);
        return paths;
    }

    getPaths(node, path, paths) {
        if (node === null) {
            return;
        }

        path.push(node.data);

        if (node.left === null && node.right === null) {
            paths.push(path);
        } else {
            this.getPaths(node.left, path.slice(), paths);
            this.getPaths(node.right, path.slice(), paths);
        }
    }
}

function solve() {
    let n = parseInt(readline());
    let input = readline().split(' ').map(item => parseInt(item));

    let bt = new BinaryTree();
    input.forEach(item => bt.add(item));

    let maxLength = 0;
    let paths = [];
    bt.root.left && bt.root.right && bt.longestDeccPath(bt.root.left) > bt.longestDeccPath(bt.root.right) ?
        this.getPaths(bt.root.left, [], paths) :
        this.getPaths(bt.root.right, [], paths);

    for (let path of paths) {
        if (path.length > maxLength) {
            maxLength = path.length;
        }
    }

    console.log(maxLength);
    console.log(paths.map(path => path.join(' ')).join('\n'));
}

The `BinaryTree` class is responsible for creating a binary tree and adding nodes. The `add` function is responsible for adding nodes to the binary tree. The `insertNode` function is responsible for inserting a new node into the binary tree. The `longestDeccPath` function is responsible for finding the longest decreasing root-to-leaf path. The `printPaths` function is responsible for printing the nodes of the longest decreasing path. The `getPaths` function is responsible for getting the paths.

The `solve` function is responsible for reading the input and processing the binary tree.