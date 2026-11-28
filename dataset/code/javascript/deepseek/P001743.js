const fs = require('fs');
process.stdin.setEncoding('utf-8');

let standardInput = process.stdin;
standardInput.setRawMode(true);
standardInput.setEncoding('utf-8');

let inputs = [];

standardInput.on('data', (input) => {
    inputs.push(input.trim());
});

standardInput.on('end', () => {
    solve(inputs);
});

function solve(inputs) {
    const tree = inputs[0].split('\n')[1].split(' ').map(Number);
    const n = tree.length;
    const treeMap = Array(n + 1).fill(0).map((_, i) => i).reduce((acc, i) => ({ ...acc, [i]: tree[i - 1] }), {});
    const queue = [1];
    while (queue.length) {
        const node = queue.shift();
        if (treeMap[node] !== undefined && treeMap[node] !== -1) {
            if (treeMap[node * 2] === -1 && treeMap[node * 2 + 1] === -1) {
                console.log(treeMap[node]);
                return;
            }
            queue.push(node * 2);
            queue.push(node * 2 + 1);
        } else {
            treeMap[node * 2] = treeMap[node * 2 + 1] = -1;
        }
    }
    console.log('None');
}