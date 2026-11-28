Here is the JavaScript code:

let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let N = parseInt(input.split('\n')[0]);
let arr1 = input.split('\n')[1].split(' ').map(Number);
let arr2 = input.split('\n')[2].split(' ').map(Number);

arr1.sort((a, b) => a - b);
arr2.sort((a, b) => a - b);

let maxIndex = 0;
for (let i = 0; i < N; i++) {
    if (arr1[i] > arr2[i]) {
        maxIndex = i;
        break;
    }
}

console.log(arr1.slice(0, maxIndex + 1).join(' '));

This code reads the input, splits it into the array lengths and the actual arrays. It then sorts both arrays in ascending order. After that, it finds the maximum index at which the elements in both arrays are not equal. Then, it prints the first part of the sorted first array up to this index. The rest of the array is left for printing.