let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let lines = input.split('\n');
let n = parseInt(lines[0]);
let tree = lines[1].split(' ').map(Number);
let max = new Array(n).fill(-1);

function maxInRow(node, depth) {
    if (node === -1) return;
    if (max[depth] < tree[node]) max[depth] = tree[node];
    maxInRow(node * 2 + 1, depth + 1);
    maxInRow(node * 2 + 2, depth + 1);
}

maxInRow(0, 0);
console.log(max.join(' '));