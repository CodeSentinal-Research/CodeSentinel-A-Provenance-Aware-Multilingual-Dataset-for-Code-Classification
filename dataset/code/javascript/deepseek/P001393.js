Here is the JavaScript code for the given problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let tests = parseInt(rl.question());

rl.on('line', (line) => {
    let [N, K] = line.split(' ').map(Number);

    let arr = rl.question().split(' ').map(Number);

    let hashMap = new Map();
    hashMap.set(0, true);
    let sum = 0;

    for (let num of arr) {
        sum += num;
        sum %= K;

        if (hashMap.has(sum) && (sum != 0 || N != 1)) {
            console.log('YES');
            return;
        }

        if (!hashMap.has(sum)) {
            hashMap.set(sum, true);
        }
    }

    console.log('NO');
    return;

});
This JavaScript code reads the test cases from standard input. It reads the first line which contains the number of test cases and then each test case is read line by line. It reads an integer array of length N and an integer K. It then checks for each subarray of size at least 2 with sum a multiple of K. If such a subarray is found, it prints 'YES', otherwise 'NO'.

Note: This code assumes that the test cases do not exceed the maximum input size (2×10^5).