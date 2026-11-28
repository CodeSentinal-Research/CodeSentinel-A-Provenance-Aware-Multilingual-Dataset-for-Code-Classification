Here is a simple JavaScript code that fulfills the problem's requirements:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N;
rl.question('Enter N: ', (n) => {
  N = parseInt(n);
  rl.setPrompt('Enter first permutation: ');
  rl.question('', (firstPermutation) => {
    firstPermutation = firstPermutation.split(' ').map(Number);
    rl.setPrompt('Enter second permutation: ');
    rl.question('', (secondPermutation) => {
      secondPermutation = secondPermutation.split(' ').map(Number);
      const commonPrefixes = findCommonPrefixes(firstPermutation, secondPermutation);
      console.log(commonPrefixes);
      rl.close();
    });
  });
});

function findCommonPrefixes(arr1, arr2) {
  const len = Math.min(arr1.length, arr2.length);
  return arr1.slice(0, len).filter((num, index) => arr2[index] === num);
}

This code uses the `readline` module in Node.js to read input from the user. It first reads the number `N` and then reads the first and second permutation. The `findCommonPrefixes` function is then used to find the common elements at each index in the two permutations, and finally the result is printed.

Note: You need to install Node.js and `readline` module to run this code.