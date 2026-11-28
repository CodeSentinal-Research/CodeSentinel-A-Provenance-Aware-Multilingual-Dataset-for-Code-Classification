let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of elements: ', (n) => {
    let arr = [];
    rl.question('Enter the elements: ', (inputs) => {
        arr = inputs.split(' ').map(Number);
        arr.sort((a, b) => a - b);
        const target = Number(rl.question('Enter the target: '));
        const result = binarySearch(arr, target, 0, arr.length - 1);
        console.log(result);
        rl.close();
    });
});

function binarySearch(arr, target, start, end) {
    if (start > end) return -1;

    const mid = Math.floor((start + end) / 2);

    if (arr[mid] === target) {
        if (mid === arr.length - 1 || arr[mid + 1] !== target) return mid;
        else return binarySearch(arr, target, mid + 1, end);
    }
    else if (arr[mid] > target) return binarySearch(arr, target, start, mid - 1);
    else return binarySearch(arr, target, mid + 1, end);
}
This program reads the number of elements and elements in the sorted array, then it finds the last occurrence of the target in the array.