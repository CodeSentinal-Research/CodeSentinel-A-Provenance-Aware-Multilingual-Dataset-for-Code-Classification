let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let N = parseInt(input.split('\n')[0]);
let array = input.split('\n')[1].split(' ').map(Number);
let sum = array.reduce((a, b) => a + b, 0);
console.log(sum);