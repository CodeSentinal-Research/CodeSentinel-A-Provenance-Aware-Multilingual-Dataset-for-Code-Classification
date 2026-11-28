const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let arr = [];

rl.on('line', (line) => {
    arr = line.split(' ').map(Number);
    countSubarrays();
}).on('close', () => {
    process.stdin.close();
});

function countSubarrays() {
    let count = 0;
    let zeroCount = 0;
    let oneCount = 0;
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === 0) {
            zeroCount++;
        } else {
            oneCount++;
        }
        if (zeroCount === oneCount) {
            count += zeroCount;
        }
    }
    console.log(count);
}