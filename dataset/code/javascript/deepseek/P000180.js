let input = require('fs').readFileSync('stdin', 'utf8');
let N = parseInt(input.split('\n')[0]);
let arr = input.split('\n')[1].split(' ').map(Number);

function findAllElements(arr, N) {
    let map = new Map();
    for (let num of arr) {
        if (map.has(num)) {
            map.set(num, map.get(num) + 1);
        } else {
            map.set(num, 1);
        }
    }
    let result = [];
    for (let [num, count] of map) {
        if (count > N / 3) {
            result.push(num);
        }
    }
    result.sort((a, b) => a - b);
    return result;
}

console.log(findAllElements(arr, N).join(' '));