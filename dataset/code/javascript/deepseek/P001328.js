Here is the JavaScript code for the problem:

let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let N = Number(input.split('\n')[0]);
let arr = input.split('\n')[1].split(' ').map(Number);

function permutations(arr, prefix='') {
  if (arr.length === 0) {
    console.log(prefix);
  } else {
    for (let i = 0; i < arr.length; i++) {
      let smallerArray = arr.slice(0, i).concat(arr.slice(i + 1));
      permutations(smallerArray, prefix + arr[i]);
    }
  }
}

permutations(arr);

This code reads the number N and the array from standard input. The `permutations` function is a recursive function that prints all possible permutations of the array. It takes an array and a prefix as input, and recursively calls itself with the remaining elements and the current prefix. If the array is empty, it prints the prefix.