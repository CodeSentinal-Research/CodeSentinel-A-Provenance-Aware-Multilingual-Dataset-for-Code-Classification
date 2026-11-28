const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N = 0, arr = [];

rl.on('line', (line) => {
  if(N === 0) {
    [N, arr[0]] = line.split(' ').map(n => parseInt(n));
  } else {
    arr.push(parseInt(line));
  }
});

rl.on('close', () => {
  const target = parseInt(arr.pop());
  const index = binarySearch(arr, target);
  console.log(index === -1 ? -1 : index);
  process.exit();
});

function binarySearch(arr, target) {
  let left = 0, right = arr.length - 1;

  while(left <= right) {
    const mid = Math.floor((left + right) / 2);

    if(arr[mid] === target) {
      return mid;
    } else if(arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}