Here is the JavaScript code for your problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let arr = [];

rl.on('line', function(line) {
  arr = line.split(' ').map(Number);
  rl.close();
}).on('close', function() {
  console.log(countGreaterThanRoot(arr));
  process.exit();
});

function countGreaterThanRoot(arr) {
  let count = 0;
  for(let i = 2; i < arr.length; i++) {
    if(arr[i] > arr[1]) count++;
  }
  return count;
}

In this code, we use the `readline` module to read input from the console. We create an array `arr` and read the input line by line. The line is split into an array of strings using `split(' ')`, each string is converted to a number using `map(Number)`, and we read the number of elements in the array.

When all the elements have been read, we call the function `countGreaterThanRoot` to count the number of nodes that are greater than the root.

Please note that this code assumes that the Max Heap is represented as an array where the root is at index 1, and all other nodes are less than their parent (i.e., they are a max heap).