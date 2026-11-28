Here is the JavaScript code for the given problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let inputs = [];

rl.on('line', function(line) {
  inputs = line.split(' ').map(Number);
  rl.close();
});

rl.on('close', function() {
  processInputs(inputs);
});

function processInputs([N, K]) {
  let arr = new Array(K).fill(0);
  let maxRepeatingNum = 0;
  let maxRepeatingCount = 0;

  inputs.forEach(num => arr[num] += 1);

  arr.forEach((count, index) => {
    if (count > maxRepeatingCount) {
      maxRepeatingNum = index;
      maxRepeatingCount = count;
    }
  });

  console.log(maxRepeatingNum);
}

In this code, we use a readline interface to handle the input from the user. We create an array of size K with all elements initialized to 0. We then iterate through the input array and update the count of each element in the array. The element with the maximum count is the maximum repeating number.

You can test this program by running it and providing the inputs through the console.