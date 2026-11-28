const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputs = [];

rl.on('line', (line) => {
    inputs.push(parseInt(line));
    if (inputs.length == 2) {
        rl.close();
    }
}).on('close', () => {
    findElement(inputs[0], inputs[1]);
});

function findElement(n, target, start = 0, end = n - 1) {
    if (start > end) {
        console.log(-1);
        return;
    }

    let mid = Math.floor((start + end) / 2);

    if (arr[mid] == target) {
        console.log(mid);
        return;
    }

    if (arr[start] <= arr[mid]) { // left part is sorted
        if (target >= arr[start] && target < arr[mid]) {
            findElement(mid, target, start, mid - 1);
        } else {
            findElement(mid + 1, target, mid + 1, end);
        }
    } else { // right part is sorted
        if (target > arr[mid] && target <= arr[end]) {
            findElement(mid, target, mid + 1, end);
        } else {
            findElement(start, mid - 1, start, mid - 1);
        }
    }
}

const arr = [4, 5, 1, 2, 3];
findElement(0, 5);
This JavaScript program uses binary search to find the target in a rotated sorted array. The program takes an array and a target as input, and returns the index of the target in the array. If the target is not found, it returns -1. The `findElement` function uses a helper function `midpoint` to find the midpoint of the array. If the target is in the left part of the array, it checks if it's in the range of the start and midpoint. If not, it checks if it's in the range of midpoint and end. If the target is in the right part of the array, it checks if it's in the range of midpoint and end. If not, it checks if it's in the range of start and midpoint. If all these conditions are met, it returns the midpoint. If not, it recurses on the appropriate part of the array.