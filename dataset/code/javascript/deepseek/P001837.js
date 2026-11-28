class Node {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

class BST {
    constructor() {
        this.root = null;
    }

    add(value) {
        const node = this.root;
        if (node === null) {
            this.root = new Node(value);
            return;
        }
        let current = node;
        while (current !== null) {
            if (value < current.value) {
                if (current.left === null) {
                    current.left = new Node(value);
                    return;
                }
                current = current.left;
            } else {
                if (current.right === null) {
                    current.right = new Node(value);
                    return;
                }
                current = current.right;
           
        }
    }
}

class ReverseInorderIterator {
    constructor(root) {
        this.stack = [];
        this.rightmostChild(root);
    }

    next() {
        if (this.stack.length === 0) {
            return null;
        }
        let node = this.stack.pop();
        this.rightmostChild(node.right);
        return node.value;
    }

    rightmostChild(node) {
        while (node !== null) {
            this.stack.push(node);
            node = node.right;
        }
    }
}

function main() {
    const bst = new BST();
    const iterator = new ReverseInorderIterator(bst.root);

    const readline = require('readline');
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });

    rl.on('line', (line) => {
        const operation = line.trim();
        if (operation === 'PREV') {
            console.log(iterator.next());
        } else if (operation === 'HASPREV') {
            console.log(iterator.stack.length > 0 ? 'yes' : 'no');
        } else {
            const value = parseInt(operation, 10);
            bst.add(value);
        }
    });
}

main();