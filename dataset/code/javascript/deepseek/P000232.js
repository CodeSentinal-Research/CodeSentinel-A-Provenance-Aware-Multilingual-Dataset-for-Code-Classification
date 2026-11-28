Here's the JavaScript code for finding the median in a row-wise sorted matrix of odd dimensions:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let matrix = [];

rl.question('Enter rows and cols: ', (rows) => {
  rl.question('Enter the matrix: ', (input) => {
    matrix = input.split(' ').map(item => parseInt(item));

    let median;
    let sum = 0;
    let count = 0;
    for (let i = 0; i < matrix.length; i++) {
      if (matrix[i] < matrix[i - 1]) {
        sum += matrix[i - 1];
        count++;
      }
      if (count === rows / 2) {
        median = matrix[i];
        break;
      }
    }

    console.log(median);
    rl.close();
  });
});

This program first reads the number of rows and columns, then the matrix. It then calculates the median by summing up all elements that are less than the previous element. It stops summing as soon as it reaches the middle element of the matrix. The median is the last element that was summed up.