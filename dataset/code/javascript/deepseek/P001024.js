Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let testCases = parseInt(rl.readline());

rl.once('line', () => {
  testCases--;
  if (testCases === 0) {
    process.exit();
  }
});

while (testCases--) {
  let [n, m] = rl.readline().split(' ').map(Number);
  let arr = rl.readline().split(' ').map(Number);
  let i = rl.readline().split(' ').map(Number);

  let left = arr[i[0]] * 2;
  let right = arr[i[1]] * 2;

  console.log(`Left child of ${i[0] + 1}: ${left === -1 ? ' -1' : left}`);
  console.log(`Right child of ${i[0] + 1}: ${right === -1 ? ' -1' : right}`);
}

rl.close();

In this code, we first read the number of test cases, then for each test case, we read the size of the array, array itself, and the indices of the node we need to access. We then check for the left and right children of the given node. If the left child or the right child doesn't exist, we print -1 instead.