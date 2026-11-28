Here's the JavaScript code that solves the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputs = [];

rl.on('line', (line) => {
    inputs.push(Number(line));
    if(inputs.length === 2) {
        rl.close();
    }
});

rl.on('close', () => {
    console.log(checkMaxHeap(inputs[1], inputs[0] - 1, 1));
});

function checkMaxHeap(arr, i, n) {
    if(i >= n) {
        return true;
    }

    let left = 2 * i + 1;
    let right = 2 * i + 2;

    if(left < n && arr[left] > arr[i]) {
        return false;
    }

    if(right < n && arr[right] > arr[i]) {
        return false;
    }

    return checkMaxHeap(arr, left, n) && checkMaxHeap(arr, right, n);
}

This code uses the Readline module from Node.js to read the input from the standard input. The inputs are stored in an array `inputs`. When a line of input is read, it's converted to a number and added to the array. When two inputs have been read, the process is terminated and the input is checked to see if it represents a Max Heap.

Please note that the maximum length of inputs is limited by the constraint of the problem, so make sure that your inputs fit within this limit.