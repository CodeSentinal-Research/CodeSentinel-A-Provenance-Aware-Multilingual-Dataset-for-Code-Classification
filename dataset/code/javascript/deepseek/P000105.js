let input = require('fs').readFileSync('stdin', 'utf8');
let N = Number(input.split('\n')[0]);
let arr = input.split('\n')[1].split(' ').map(Number);
let evenCount = arr.filter(num => num % 2 === 0).length;
let oddCount = arr.filter(num => num % 2 !== 0).length;
console.log(evenCount + ' ' + oddCount);