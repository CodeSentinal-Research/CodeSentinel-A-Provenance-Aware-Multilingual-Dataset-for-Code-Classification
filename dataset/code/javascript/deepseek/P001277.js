Here is a simple JavaScript code to solve the problem:

let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N = parseInt(rl.question(''));

let arr = rl.question('').split(' ').map(Number);

let chunks = arr.reduce((acc, curr, i) => {
  let sortedArr = [...acc];
  sortedArr.push(curr);
  
  if(sortedArr.every((num, index) => num >= sortedArr[index - 1])) {
    return [...acc, curr];
  }

  return acc;
}, []);

console.log(chunks.length);

rl.close();

This code reads the number of elements `N` and the array from the user. Then, it partitions the array into chunks by checking if each chunk is sorted in increasing order. If a chunk is sorted, it adds the chunk to the result.

Note: This code assumes that the array is provided in the correct format. It may not work correctly if the array is not correctly formatted (e.g., if the user inputs a string instead of a number).