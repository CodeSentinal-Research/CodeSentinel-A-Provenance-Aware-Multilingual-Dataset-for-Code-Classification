Here is a simple solution using JavaScript:

let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let num1 = parseInt(rl.question().split(" ")[0]);
let arr1 = rl.question().split(" ").slice(1).map(Number);

let num2 = parseInt(rl.question().split(" ")[0]);
let arr2 = rl.question().split(" ").slice(1).map(Number);

let arr3 = arr1.filter(value => arr2.includes(value));

arr3 = arr3.sort((a, b) => a - b);
arr3 = arr3.join(" ");

console.log(arr3);

rl.close();

This code reads two arrays from the user, then filters the first array to include only the elements that are also in the second array. The result is then sorted and printed. The readline module is used to read the user's input and the console module is used to output the result.