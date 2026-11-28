Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

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

    insert(data) {
        const node = new Node(data);
        if (!this.root) {
            this.root = node;
        } else {
            let current = this.root;
            while (current) {
                if (node.data < current.data) {
                    if (!current.left) {
                        current.left = node;
                        break;
                    }
                    current = current.left;
                } else {
                    if (!current.right) {
                        current.right = node;
                        break;
                    }
                    current = current.right;
                }
            }
        }
    }

    maxWidth() {
        if (!this.root) return 0;
        let queue = [this.root];
        let width = 0;
        while (queue.length) {
            width = Math.max(width, queue.length);
            let len = queue.length;
            for (let i = 0; i < len; i++) {
                if (queue[i].left) queue.push(queue[i].left);
                if (queue[i].right) queue.push(queue[i].right);
            }
            queue.length = len;
        }
        return width;
    }
}

rl.question('Enter the number of nodes: ', (num) => {
    const tree = new BinaryTree();
    rl.setPrompt('Enter node data: ');
    rl.prompt();
    for (let i = 0; i < num; i++) {
        const data = rl.line.split(' ');
        tree.insert(parseInt(data[0]));
    }
    console.log(tree.maxWidth());
    rl.close();
});

This code creates a binary tree and then calculates the maximum width of the tree. The binary tree is created by reading an input where each line contains the data of a node in the binary tree. The maximum width is then printed out.