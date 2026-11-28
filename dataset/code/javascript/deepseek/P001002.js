Here is the JavaScript code that checks if the given array represents a Max Heap:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let array = [];

rl.on('line', function(line) {
    array = line.split(' ').map(Number);
    rl.close();
}).on('close', function() {
    if (isMaxHeap(array, 0, array.length - 1)) {
        console.log('YES');
    } else {
        console.log('NO');
    }
    process.exit();
});

function isMaxHeap(arr, start, end) {
    if (start > end) {
        return true;
    }

    if (arr[start] < arr[2 * start + 1] && (2 * start + 2 == end + 1 || arr[2 * start + 2] >= arr[start])) {
        return isMaxHeap(arr, 2 * start + 1, end) && isMaxHeap(arr, 2 * start + 2, end);
    }

    return false;
}

This code reads an array from the standard input and checks if it represents a Max Heap. It does this by recursively checking if the subtree rooted at the current node and its children satisfy the Max Heap property.