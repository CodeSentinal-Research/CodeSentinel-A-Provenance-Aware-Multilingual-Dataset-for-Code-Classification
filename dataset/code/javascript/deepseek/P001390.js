Here's a simple JavaScript code that solves the problem:

let input = require('fs').readFileSync('stdin', 'utf8');
let N = parseInt(input.split('\n')[0]);
let arr = input.split('\n')[1].split(' ').map(Number);

function longestZeroSumSubarray(arr) {
    let maxLength = 0;
    let sum = 0;
    let map = new Map();

    for (let num of arr) {
        sum += num;

        if (map.has(sum)) {
            maxLength = Math.max(maxLength, map.get(sum) + 1);
        } else {
            map.set(sum, 0);
        }
    }

    return maxLength;
}

console.log(longestZeroSumSubarray(arr));
This code reads the input from stdin and uses a map to store the prefix sum and its occurrence. When a sum is seen for the first time, it's stored in the map. Then, for each sum, if it's the first occurrence, it's stored in the map. If not, the map stores the length of the longest sum ending at this sum.