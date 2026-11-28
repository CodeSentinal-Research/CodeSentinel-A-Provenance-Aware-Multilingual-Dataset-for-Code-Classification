let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = parseInt(rl.question().trim());
let deliciousness = rl.question().trim().split(' ').map(item => parseInt(item));

let count = 0;

for (let i = 0; i < N; i++) {
    for (let j = i + 1; j < N; j++) {
        if ((deliciousness[i] + deliciousness[j]) & (deliciousness[i] + deliciousness[j]) === deliciousness[i] + deliciousness[j]) {
            count++;
        }
    }
}

console.log(count);
rl.close();