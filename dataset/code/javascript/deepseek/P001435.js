Here is the JavaScript code for the given problem:

let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let inputs = [];

rl.on('line', function(line) {
    inputs.push(line.split(' '));
});

rl.on('close', function() {
    const [N, M] = inputs[0];
    const arr1 = new Map(inputs[1]);
    const arr2 = new Map(inputs[2]);
    let count = 0;

    arr2.forEach((value, key) => {
        if (arr1.has(key) && arr1.get(key) === 1 && value === 1) count++;
    });

    console.log(count);
    process.exit();
});

This code uses the readline module to handle command line inputs. The `rl.on('line')` callback function is triggered each time a new line is read from the input. It splits the line into an array of words and pushes it to the `inputs` array.

The `rl.on('close')` callback function is triggered when all lines have been read. It gets the first line as the number of inputs (N and M), then uses the input arrays as map to get the count of common words.

The count is printed out and the process ends.