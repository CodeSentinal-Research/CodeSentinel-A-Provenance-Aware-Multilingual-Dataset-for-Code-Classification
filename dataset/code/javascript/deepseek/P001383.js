Here is the JavaScript code to solve the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let arr1 = [];
let arr2 = [];

rl.question('Enter the size of the first array: ', (size1) => {
  rl.question('Enter the elements of the first array: ', (input1) => {
    arr1 = input1.split(' ').map(Number);

    rl.question('Enter the size of the second array: ', (size2) => {
      rl.question('Enter the elements of the second array: ', (input2) => {
        arr2 = input2.split(' ').map(Number);

        let intersection = arr1.filter(value => arr2.includes(value));
        console.log(intersection);

        rl.close();
      });
    });
  });
});

In this code, we use readline module to read input from the standard input (console). We create two arrays, `arr1` and `arr2`, and ask for their sizes and elements respectively. We then filter the first array based on the `includes` method of the JavaScript array object to get the intersection of the two arrays. The filtered array is then printed out.