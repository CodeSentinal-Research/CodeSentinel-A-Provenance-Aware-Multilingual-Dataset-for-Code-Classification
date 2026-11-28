Here is the JavaScript code for the given problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the size of the array: ', (size) => {
  rl.question('Enter elements of the array (space separated): ', (input) => {
    const arr = input.split(' ').map(Number);

    let count = 0;
    let diff = arr[1] - arr[0];

    for (let i = 2; i < size; i++) {
      if (arr[i] - arr[i - 1] === diff) {
        count++;
      } else {
        diff = arr[i] - arr[i - 1];
      }
    }

    console.log(count);

    rl.close();
  });
});

This code uses the Readline module from Node.js to read from the standard input. It first asks for the size of the array from the user, then asks for the elements of the array. The array is read as a space-separated string, and each element is converted to a number. The code then counts the number of arithmetic slices in the array, and finally prints the count to the standard output.