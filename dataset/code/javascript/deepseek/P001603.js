const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('', N => {
    rl.question('', X => {
        rl.question('', (Ai) => {
            let a = Ai.split(' ').map(Number);
            let prefixLength = findMinPrefixLength(a, X);
            console.log(prefixLength === -1 ? -1 : `${prefixLength}\n`);
            rl.close();
        });
    });
});

function findMinPrefixLength(a, X) {
    let left = 0, right = 1;
    let prefixSum = a[0];
    while (left <= right) {
        if (prefixSum >= X) {
            right--;
            prefixSum -= a[right + 1];
        } else {
            left++;
            prefixSum += a[left];
        }
    }
    return left;
}
This JavaScript code first reads the inputs from the standard input and then calls a function `findMinPrefixLength` that checks the smallest prefix length for the sum of integers to be at least X. If no such prefix exists, it returns -1.