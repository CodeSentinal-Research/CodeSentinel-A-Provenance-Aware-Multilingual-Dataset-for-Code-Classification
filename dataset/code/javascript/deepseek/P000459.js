Here is the JavaScript code to solve the problem:

let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of elements: ', (num) => {
    rl.question('Enter elements: ', (elements) => {
        const arr = elements.split(' ').map(Number);
        console.log(findPeak(arr));
        rl.close();
    });
});

function findPeak(arr) {
    let start = 0;
    let end = arr.length - 1;

    while (start < end) {
        const mid = Math.floor((start + end) / 2);

        if (arr[mid] > arr[mid + 1]) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }

    return arr[start];
}

This code reads the number of elements followed by the elements, then finds the peak in the bitonic array using binary search. The binary search algorithm is used to find the peak element in the array. The `findPeak` function takes an array as input and finds the peak element in the array.