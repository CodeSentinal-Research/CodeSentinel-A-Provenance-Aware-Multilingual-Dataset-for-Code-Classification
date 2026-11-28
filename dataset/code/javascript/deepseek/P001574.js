Here is the JavaScript code that solves the problem:

let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputs = [];

rl.on('line', function(line) {
    inputs.push(line);
    if(inputs.length == 2) {
        rl.close();
        solve(inputs[0], inputs[1]);
    }
});

function solve(n, k) {
    let [arrStr, kStr] = [n, k];
    let arr = arrStr.split(' ').map(Number);
    let k = Number(kStr);

    // find maximum in the first window
    let max = Math.max(...arr.slice(0, k));
    console.log(max);

    // slide the window and find maximum in each iteration
    for(let i = k; i < n; i++) {
        max = Math.max(max, arr[i]);
        if(i == k) {
            arr.shift();
        }
        arr.push(arr[i - k]);
    }
}

This JavaScript code reads the input as strings, converts them to numbers, and then processes the input in a straightforward way. The function `solve` takes two numbers as input (`n` and `k`), and it calculates the maximum element in the first contiguous subarray of size `k`. It then moves to the next window, and updates the maximum element in each iteration.