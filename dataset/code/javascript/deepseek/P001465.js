Here is the JavaScript solution for the problem:

let readline = require('readline');
let rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N = parseInt(rl.question().split(' ')[0]);
let arr = rl.question().split(' ').slice(1).map(Number);

let squaredArr = arr.map(el => el * el).sort((a, b) => a - b);

console.log(squaredArr.join(' '));

This script first reads the number of elements N from the input and then reads the elements of the array from the input. It then maps each element in the array to its square, sorts the array in non-decreasing order using the sort() method, and prints the sorted array.