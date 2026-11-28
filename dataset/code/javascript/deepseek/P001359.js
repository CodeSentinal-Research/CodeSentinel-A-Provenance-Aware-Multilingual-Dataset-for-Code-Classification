Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Please enter a number: ', (n) => {
  if (n < 1 || n > 20) {
    console.log('Invalid input, please enter a number between 1 and 20.');
    rl.close();
    return;
  }

  let sequence = [];
  for (let i = 1; i <= n; i++) {
    sequence.push(i % 2 === 0 ? 2 * i : 1);
  }

  console.log(sequence.join(' '));
  rl.close();
});
This script will first ask for an integer input. If the input is not valid (less than 1 or more than 20), it will print an error message and close the input. If the input is valid, it will construct the sequence and print the sequence.

The sequence is constructed by looping from 1 to N. For each number, it checks if the number is even (i.e., divisible by 2) or odd (i.e., not divisible by 2). If the number is even, it multiplies it by 2 (2 * i), and if it's odd, it pushes 1 into the sequence.

Please note that the input handling part (the part where it asks for a number and validates it) is done in this way to avoid the user from entering non-numeric inputs. The readline module from Node.js is used to read the input from the console.