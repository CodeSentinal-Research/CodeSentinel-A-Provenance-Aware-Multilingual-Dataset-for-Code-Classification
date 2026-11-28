Sure, here is the JavaScript solution for the problem. This solution uses the concept of a level map and bfs algorithm to solve the problem.

class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class Queue {
    constructor() {
        this.items = [];
    }

    enqueue(element) {
        this.items.push(element);
    }

    dequeue() {
        if (this.isEmpty()) {
            return undefined;
        }
        return this.items.shift();
    }

    isEmpty() {
        return (this.items.length == 0);
    }
}

function topView(root) {
    let map = new Map();
    let queue = new Queue();
    queue.enqueue([root, 0]);

    while (!queue.isEmpty()) {
        let pair = queue.dequeue();
        root = pair[0];
        let column = pair[1];

        if (!map.has(column)) {
            map.set(column, root.data);
        }

        if (root.left) {
            queue.enqueue([root.left, column - 1]);
        }

        if (root.right) {
            queue.enqueue([root.right, column + 1]);
       
        }
    }

    for (let pair of map) {
        console.log(pair[1]);
    }
}

To handle the input in Node.js, you can use the readline module:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let root = null;

rl.on('line', (line) => {
    // Create binary tree here
    // For now, we'll just use the provided data
    root = new Node(parseInt(line));
}).on('close', () => {
    topView(root);
    process.exit();
});

This is a basic solution and may not work for all inputs. The code assumes that the input is a simple binary tree. It also does not handle non-binary tree inputs. The actual code to construct a binary tree would be more complex.