Here is the JavaScript code to solve the given problem.

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr = [];

rl.on('line', (line) => {
    arr = line.split(' ').map(Number);
    if (arr.length === 1) {
        rl.close();
    }
}).on('close', () => {
    const [N, Q, ...rest] = arr;
    const queries = rest.map(Number);

    for (let i = 0; i < Q; i++) {
        const [L, R] = rest[i * 2].split(' ').map(Number);
        if (isArithmetic(arr, L - 1, R - 1)) {
            console.log('YES');
        } else {
            console.log('NO');
        }
    }
    process.exit();
});

function isArithmetic(arr, start, end) {
    if (end - start < 2) {
        return true;
    }

    const d = arr[start + 1] - arr[start];
    for (let i = start + 2; i <= end; i++) {
        if (arr[i] - arr[i - 1] !== d) {
            return false;
        }
    }

    return true;
}

In this code, we are using the Readline module to get the input from the user. We are reading a line at a time and storing the integers in an array. Once all lines are read, we are checking each query.

In `isArithmetic` function, we are checking if the difference between consecutive elements is the same for every subarray. If yes, then the array can be rearranged to form an arithmetic sequence.