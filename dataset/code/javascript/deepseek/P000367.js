Here is a simple JavaScript code to solve the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N = parseInt(rl.question(''));

let arr = [];
rl.setPrompt('Enter string: ');

for (let i = 0; i < N; i++) {
  arr.push(rl.question(''));
}

let shortestIndex = 0;
let shortestLength = arr[0].length;

for (let i = 1; i < N; i++) {
  if (arr[i].length < shortestLength) {
    shortestLength = arr[i].length;
    shortestIndex = i;
  }
}

console.log(shortestIndex);

This code reads the number of strings `N` from the standard input, then reads each string one by one. It then iterates over the list of strings, comparing the length of each string with the length of the shortest string found so far. If a shorter string is found, the index and length of the shortest string are updated. Finally, the index of the shortest string is printed to the standard output.