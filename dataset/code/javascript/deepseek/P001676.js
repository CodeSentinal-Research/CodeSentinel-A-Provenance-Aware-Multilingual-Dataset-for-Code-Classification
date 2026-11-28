Below is the JavaScript code for the problem. The code uses a binary tree and then uses a level order traversal to traverse the tree from top to bottom and left to right. The nodes are then grouped by their anti-diagonal coordinates.

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
    
    levelOrderTraversal() {
        let queue = [];
        let result = [];
        let node;
        let level = 0;
        
        if (this.root === null) {
            return result;
        }
        
        queue.push(this.root);
        
        while (queue.length > 0) {
            let length = queue.length;
            let subArray = [];
            
            for (let i = 0; i < length; i++) {
                node = queue.shift();
                
                subArray.push(node.data);
                
                if (node.left !== null) {
                    queue.push(node.left);
                }
                
                if (node.right !== null) {
                    queue.push(node.right);
                }
            }
            
            result[level] = subArray;
            level++;
        }
        
        return result;
    }
}

// Input handling
process.stdin.resume();
process.stdin.on('data', (chunk) => {
    const N = parseInt(chunk.toString().trim());
    let binaryTree = new BinaryTree();

    binaryTree.root = new Node(process.stdin.read()[0]);
    let currentNode = binaryTree.root;

    for (let i = 1; i < N; i++) {
        const data = parseInt(process.stdin.read()[0]);
        currentNode.left = new Node(data);
        currentNode = currentNode.left;
    }

    for (let i = 1; i < N; i++) {
        const data = parseInt(process.stdin.read()[0]);
        currentNode.right = new Node(data);
        currentNode = currentNode.right;
    }

    const result = binaryTree.levelOrderTraversal();

    for (let i = 0; i < result.length; i++) {
        console.log(result[i].join(" "));
    }
});

Please note that this code requires Node.js v8.x or later. Also, remember to install the readline module by running `npm install readline`.

This code will accept the input from the standard input. The first line is the number of nodes in the binary tree, followed by the data of each node from left to right. This is followed by the data of each node from right to left. The output is the nodes of each level of the binary tree in anti-diagonal order.