let input = require('fs').readFileSync('stdin', 'utf8');
let lines = input.split('\n');
let N = parseInt(lines[0]);
let arr = lines[1].split(' ').map(Number);

let count = 0;
let map = new Map();

for (let i = 0; i < N; i++) {
    if (!map.has(arr[i])) {
        map.set(arr[i], true);
    }
}

count = map.size;

console.log(count);