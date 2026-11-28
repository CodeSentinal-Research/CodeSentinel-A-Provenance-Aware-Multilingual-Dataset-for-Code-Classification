let input = require('fs').readFileSync('stdin').toString().split('\n');
let N = parseInt(input[0]);
let arr = input[1].split(' ').map(Number);

function longestConsecutive(arr) {
    let maxLength = 0;
    let currentLength = 1;

    for(let i = 1; i < arr.length; i++) {
        if(arr[i] - arr[i - 1] === 1) {
            currentLength++;
        } else if(arr[i] === arr[i - 1]) {
            continue;
        } else {
            maxLength = Math.max(maxLength, currentLength);
            currentLength = 1;
        }
    }

    return Math.max(maxLength, currentLength);
}

console.log(longestConsecutive(arr));