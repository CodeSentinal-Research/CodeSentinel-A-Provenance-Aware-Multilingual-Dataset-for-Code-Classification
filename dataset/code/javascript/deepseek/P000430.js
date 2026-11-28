var input = require('fs').readFileSync('stdin', 'utf8');
var N = Number(input.split('\n')[0]);
var arr = input.split('\n')[1].split(' ').map(Number);
var target = Number(input.split('\n')[2]);

function lastOccurrence(arr, target) {
    for (let i = arr.length - 1; i >= 0; i--) {
        if (arr[i] === target) {
            return i;
        }
    }
    return -1;
}

console.log(lastOccurrence(arr, target));