Sure, here is the JavaScript code for your problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter a string: ', (str) => {
  rl.question('Enter K: ', (k) => {
    if (!/^[a-z]+$/i.test(str) || isNaN(k) || k > str.length || k < 1) {
      rl.setPrompt('Invalid input!');
      return rl.close();
    }
    kthPermutation(str, k);
    rl.close();
  });
});

function kthPermutation(str, k) {
  const arr = Array.from(str);
  arr.sort();
  const factorial = (n) => {
    let res = 1;
    for (let i = 2; i <= n; i++) {
      res *= i;
    }
    return res;
  };
  const getPermutation = (arr, factorial) => {
    if (arr.length === 1) {
      return arr[0];
    }
    const index = Math.floor(Math.random() * factorial(arr.length - 1));
    return arr.splice(index, 1)[0] + getPermutation(arr.slice(0, arr.length - 1), factorial(arr.length - 1));
  };
  console.log(getPermutation(arr, factorial(arr.length)));
}

This code will take the string and integer k as input from the user, and then print the kth permutation of the string. The `kthPermutation` function uses the `getPermutation` helper function to generate and print the kth permutation. The `getPermutation` function generates a random permutation by selecting a random index from the given array, and then recursively calling `getPermutation` on the sliced array. The `factorial` function calculates the factorial of a given number.