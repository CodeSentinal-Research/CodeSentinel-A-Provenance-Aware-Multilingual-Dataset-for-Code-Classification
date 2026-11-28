let _ = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = parseInt(readline().split(' ')[0]);
let arr = readline().split(' ').map(Number);

let prefixSum = [arr[0]];

for(let i = 1; i < N; i++) {
    prefixSum[i] = prefixSum[i - 1] + arr[i];
}

let count = 0;
for(let i = 0; i < N; i++) {
    if(prefixSum[i] < 0) {
        count++;
    }
}

console.log(count);