Here is the JavaScript code to solve the problem. This solution uses a binary search tree to traverse the BST and find the closest key to the target value.

class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class BST {
    constructor() {
        this.root = null;
    }

    insert(data) {
        let newNode = new Node(data);
        if (this.root === null) {
            this.root = newNode;
        } else {
            this.insertNode(this.root, newNode);
        }
    }

    insertNode(node, newNode) {
        if (newNode.data < node.data) {
            if (node.left === null) {
                node.left = newNode;
            } else {
                this.insertNode(node.left, newNode);
            }
        } else {
            if (node.right === null) {
                node.right = newNode;
            } else {
                this.insertNode(node.right, newNode);
            }
        }
    }

    closestValue(node, target) {
        let current = node;
        let closest;

        while (current !== null) {
            closest = Math.abs(target - current.data) < Math.abs(target - closest) ? current.data : closest;
            current = target < current.data ? current.left : current.right;
        }

        return closest;
    }
}

let bst = new BST();
process.stdin.setEncoding('utf8');
process.stdin.on('data', (input) => {
    const N = parseInt(input.trim(), 10);
    const data = [];
    let inputs = [];

    for (let i = 0; i < N; i++) {
        inputs.push(parseInt(process.stdin.readLine().trim(), 10));
    }

    let target = parseInt(process.stdin.readLine().trim(), 10);

    inputs.forEach((num) => {
        bst.insert(num);
    });

    let closestValue = bst.closestValue(bst.root, target);

    process.stdout.write(closestValue.toString() + '\n');

    process.stdin.end();
});

To run this code, you need to provide input data to the stdin. The first line of input is the number of nodes, followed by the node values. The target value to find the closest key is the last line of input.

Example:
5
5
1
15
10
14
1
15
This would find the closest value in the BST to the given target value.