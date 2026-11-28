let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr = [];

rl.on('line', (line) => {
    if (line !== '') {
        arr.push(parseInt(line));
    }
});

rl.on('close', () => {
    console.log(minProduct(arr));
});

function minProduct(arr) {
    if (arr.length < 2) {
        throw 'Invalid input, at least two elements are required';
    }

    let min1 = arr[0], min2 = arr[0];
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2) {
            min2 = arr[i];
        }
    }

    return min1 * min2;
}