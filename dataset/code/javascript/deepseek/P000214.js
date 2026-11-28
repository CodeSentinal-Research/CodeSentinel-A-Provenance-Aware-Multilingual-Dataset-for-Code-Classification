const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the size of the array: ', (size) => {
  let arr = [];
  rl.question('Enter the elements of the array: ', (input) => {
    arr = input.split(' ').map(Number);

    let missing = [];
    for(let i = 1; i <= size; i++) {
      if(!arr.includes(i)) {
        missing.push(i);
      }
    }

    console.log('Missing numbers: ', missing.join(', '));

    rl.close();
  });
});
This program first reads the size of the array and then the elements of the array. It then iterates from 1 to the size of the array, checks if each number is in the array. If it's not, it's missing and is pushed into a `missing` array. The program then prints all the missing numbers.