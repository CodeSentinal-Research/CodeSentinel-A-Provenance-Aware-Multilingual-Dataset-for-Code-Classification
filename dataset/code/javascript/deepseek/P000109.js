function linearSearch(arr, target) {
    for(let i = 0; i < arr.length; i++) {
        if(arr[i] === target) {
            return i;
        }
    }
    return -1;
}

const [N, target] = require('fs').readFileSync('dev/stdin', 'utf8').split('\n');
const arr = require('fs').readFileSync('dev/stdin', 'utf8').split(' ').map(Number);

console.log(linearSearch(arr, target));