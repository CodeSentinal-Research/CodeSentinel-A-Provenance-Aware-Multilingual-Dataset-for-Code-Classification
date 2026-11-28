const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let [N, K] = rl.question('Enter two numbers: ').split(" ").map(x => parseInt(x));

let arr = rl.question('Enter N numbers: ').split(" ").map(x => parseInt(x));

let count = 0;
let map = new Map();

for(let i = 0; i < N; i++) {
    if(map.has(arr[i])) {
        map.get(arr[i]).push(i);
    } else {
        map.set(arr[i], [i]);
    }
}

for(let [num, indexes] of map.entries()) {
    if(indexes.length > 1) {
        for(let i = 0; i < indexes.length - 1; i++) {
            if(indexes[i + 1] - indexes[i] == K) count++;
        }
    }
}

console.log(count);

rl.close();