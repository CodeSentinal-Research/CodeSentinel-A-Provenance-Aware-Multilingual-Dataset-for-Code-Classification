Here is the JavaScript code to solve the given problem:

let readline = require('readline');

let input = [];

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of elements: ', (n) => {
    rl.question('Enter the elements: ', (elements) => {
        input = elements.split(' ').map(Number);
        console.log(findMinDifference(input));
        rl.close();
    });
});

function findMinDifference(arr) {
    let sortedArr = arr.sort((a, b) => a - b);
    let minDiff = Infinity;

    for (let i = 0; i < sortedArr.length - 1; i++) {
        minDiff = Math.min(minDiff, Math.abs(sortedArr[i] - sortedArr[i + 1]));
    }

    return minDiff;
}

In this code, we first read the number of elements from the standard input, then we read the elements. We then sort the array in ascending order and find the minimum absolute difference between any two adjacent elements.