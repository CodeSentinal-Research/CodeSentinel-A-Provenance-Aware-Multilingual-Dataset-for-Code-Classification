const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let arr = [];

rl.question('Enter the length of array and limit: ', (limit) => {
  rl.question('Enter the elements of array: ', (input) => {
    arr = input.split(' ').map(Number);

    let start = arr[0];
    let end = arr[0];
    let minStart = arr[0];
    let maxEnd = arr[0];
    let maxLength = 1;
    let currentLength = 1;

    for(let i = 1; i < arr.length; i++) {
      if(arr[i] < minStart) {
        minStart = arr[i];
        start = arr[i];
        currentLength = 2;
      } else if(arr[i] > end) {
        end = arr[i];
        currentLength++;
      } else {
        currentLength++;
      }

      if(currentLength > maxLength) {
        maxLength = currentLength;
        maxEnd = end;
      }

      if(Math.abs(end - start) > limit) {
        if(arr[i] > end) {
          end = arr[i];
          currentLength = 2;
        } else {
          start = arr[i];
          currentLength = 1;
        }
      }
    }

    console.log(maxLength);
    rl.close();
  });
});