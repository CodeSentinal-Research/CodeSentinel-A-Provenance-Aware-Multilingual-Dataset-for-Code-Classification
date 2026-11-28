Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of elements: ', (N) => {
  rl.question('Enter the elements: ', (binaryArray) => {
    binaryArray = binaryArray.split(' ').map(Number);
    let count = 0;
    for (let i = 0; i < N - 1; i++) {
      if (binaryArray[i] === binaryArray[i + 1]) {
        count++;
      }
    }
    console.log(count);
    rl.close();
  });
});

This code uses the readline module to read from the standard input and write to the standard output. It first asks for the number of elements, then for the elements themselves. It then iterates through the array, and for each pair of consecutive elements, it checks if they are the same. If they are, it increments a counter. Finally, it prints the total count of alternating subarrays.