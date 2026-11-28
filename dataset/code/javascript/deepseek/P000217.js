const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let inputArr = [];

rl.on('line', function(line) {
  inputArr = line.split(' ').map(Number);
  findPivotIndex(inputArr);
}).on('close', function() {
  process.stdin.close();
});

function findPivotIndex(arr) {
  let leftSum = 0;
  let rightSum = arr.reduce((a, b) => a + b, 0);

  for (let i = 0; i < arr.length; i++) {
    rightSum -= arr[i];
    if (leftSum === rightSum) {
      console.log(i);
      return;
    }
    leftSum += arr[i];
  }
  console.log(-1);
}

In this code, we read the input line by line, parse it into an array of integers. Once we have all the integers, we call the `findPivotIndex` function, which will print the index of the leftmost pivot index or -1 if there is no pivot.