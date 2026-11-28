const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter array length: ', (n) => {
  rl.question('Enter target: ', (target) => {
    rl.question('Enter sorted array: ', (arrStr) => {
      let arr = arrStr.split(' ').map(Number);
      let target = Number(target);
      let start = -1, end = -1;

      // Find first position
      for(let i = 0; i < arr.length; i++) {
        if(arr[i] === target) {
          start = i;
          break;
        }
      }

      // Find last position
      for(let i = arr.length - 1; i >= 0; i--) {
        if(arr[i] === target) {
          end = i;
          break;
        }
      }

      console.log(`First position: ${start}`);
      console.log(`Last position: ${end}`);
      rl.close();
    });
  });
});

This JavaScript program uses the `readline` module to read input from the user. The `readline.createInterface` function creates a readable stream of lines from the user input. When the user enters the target and sorted array, the program will find the starting and ending position of the target in the array and log them to the console.