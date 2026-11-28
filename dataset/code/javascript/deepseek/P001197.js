const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the length of array: ', (n) => {
  rl.question('Enter the numbers: ', (numbersStr) => {
    const numbers = numbersStr.split(' ').map(Number);
    let count = 0;

    for (let i = 0; i < numbers.length; i++) {
      for (let j = i + 1; j < numbers.length; j++) {
        for (let k = j + 1; k < numbers.length; k++) {
          const diff = numbers[j] - numbers[i];
          if (numbers[k] - numbers[j] === diff) {
            count++;
          }
          if (numbers[k] - numbers[i] === diff) {
            count++;
          }
        }
      }
    }

    console.log(count);
    rl.close();
  });
});
This code is for solving the problem. The input is a line of numbers separated by spaces, and then the numbers. The program will output the count of arithmetic subsequences of length at least three.