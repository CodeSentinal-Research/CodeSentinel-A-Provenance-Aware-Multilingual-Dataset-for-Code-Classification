Here is a JavaScript solution for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let arr = [];

rl.question('Enter the number of elements: ', (num) => {
  rl.question('Enter the elements: ', (element) => {
    arr = element.split(' ').map(Number);
    arr.sort((a, b) => a - b);
    let distinctAbsValues = new Set();
    for(let i = 0; i < arr.length; i++) {
      distinctAbsValues.add(Math.abs(arr[i]));
    }
    console.log(distinctAbsValues.size);
    rl.close();
  });
});
This code will take the number of elements from the user, and then take the elements themselves. It will then sort the array, find the unique absolute values, and print the count.

Please note that this code assumes that you are using Node.js. If you're using a different environment, you may need to modify the code to fit into your environment.