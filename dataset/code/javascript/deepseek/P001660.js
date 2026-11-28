const { readInput } = require('./utils');

class Node {
    constructor(data, children = []) {
        this.data = data;
        this.children = children;
    }
}

let nodes = {};

function preOrder(root) {
    if (!root) {
        return;
    }

    let serialized = JSON.stringify(root);

    if (nodes[serialized]) {
        nodes[serialized]++;
    } else {
        nodes[serialized] = 1;
    }

    for (let child of root.children) {
        preOrder(child);
    }
}

function main() {
    let [N, ...inputs] = readInput();

    for (let i = 0; i < N; i++) {
        let [data, childrenCount, ...childData] = inputs[i].split(' ');
        let children = [];

        if (childrenCount !== '0') {
            children = childData.map((child) => {
                return new Node(child);
            });
        }

        let root = new Node(data, children);
        preOrder(root);
    }

    let duplicates = Object.keys(nodes).reduce((acc, curr) => {
        if (nodes[curr] > 1 && acc.indexOf(curr) === -1) {
            acc.push(curr);
        }
        return acc;
    }, []);

    if (duplicates.length === 0) {
        console.log('NONE');
    } else {
        duplicates.forEach((duplicate) => {
            console.log(duplicate);
        });
    }
}

main();

This script uses pre-order tree traversal to identify duplicate subtrees in a binary tree. It constructs a string representation of each node and its children using `JSON.stringify`. Then, it counts the frequency of each string using a JavaScript object (`nodes`). The script then iterates over the keys of the `nodes` object and prints the keys that have a count greater than 1.