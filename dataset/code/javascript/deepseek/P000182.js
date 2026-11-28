Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter number of elements: ', (n) => {
  rl.question('Enter elements: ', (input) => {
    const arr = input.split(' ').map(Number);
    const counts = arr.reduce((acc, val) => {
      acc[val] = (acc[val] || 0) + 1;
      return acc;
    }, {});
    const mostFrequent = Object.keys(counts).reduce((a, b) =>
      counts[a] > counts[b] ? a : b
    );
    console.log(mostFrequent);
    rl.close();
  });
});

This code uses the `readline` module to read the input from the user. It first reads the number of elements in the array, and then reads the array of elements. It then counts the frequency of each element and finds the most frequent element. The result is printed to the console.