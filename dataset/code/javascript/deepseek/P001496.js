Here is a simple JavaScript code snippet for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = parseInt(rl.question());
let arr = rl.question().split(' ').map(Number);

function solve(arr, N) {
    for (let i = 0; i < N; i++) {
        if (i % 2 === 0) {
            arr[i] *= 2;
            arr[i + 1] = 0;
        }
    }

    let zeroIndex = arr.indexOf(0);

    while (zeroIndex !== -1) {
        arr.splice(zeroIndex, 2);
        arr.push(0);
        zeroIndex = arr.indexOf(0);
    }

    console.log(arr.join(' '));
}

solve(arr, N);

This code reads the input from the user and uses it to solve the problem. The `rl.question()` function is used to read the input line, and `rl.question().split(' ').map(Number)` is used to split the input string into an array of numbers. The `solve` function is defined to process the input array and print the result.

This code assumes that the input is always valid (i.e., the array length is in the given constraints and that all elements are integers). If the input is not valid, you may need to add error checking and handling code.