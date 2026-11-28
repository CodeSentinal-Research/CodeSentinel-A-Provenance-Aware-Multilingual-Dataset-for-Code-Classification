let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let lines = input.split('\n');
let N = parseInt(lines[0]);
let stones = lines[1].split(' ').map(Number);

stones.sort((a, b) => a - b);

let total = 0;
for (let i = 1; i < N; i++) {
    total += Math.abs(stones[i] - stones[i - 1]);
}

console.log(total);