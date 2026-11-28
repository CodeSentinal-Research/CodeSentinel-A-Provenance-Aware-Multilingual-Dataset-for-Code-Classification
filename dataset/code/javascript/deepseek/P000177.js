const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N = 0;
let K = 0;
let target = 0;

rl.on('line', (line) => {
  let parts = line.split(' ');
  N = parseInt(parts[0]);
  K = parseInt(parts[1]);
  target = parseInt(parts[2]);
});

rl.on('close', () => {
  const numbers = [];

  rl.on('line', (line) => {
    numbers.push(parseInt(line));
    if (numbers.length === N) {
      const result = findClosestElements(numbers, K, target);
      console.log(result.join(' '));
      rl.close();
    }
  });
});

function findClosestElements(arr, k, target) {
  let left = 0;
  let right = arr.length - 1;
  while (left < right) {
    if (Math.abs(target - arr[left]) < Math.abs(target - arr[right])) {
      right--;
    } else {
      left++;
    }
  }
  return arr.slice(left, left + k);
}