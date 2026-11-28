const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let cases;
rl.once('line', (line) => {
  [cases, ...inputs] = line.split(' ').map(Number);
  solve(inputs);
});

function solve(inputs) {
  let maxLength = 0;
  let countZero = 0;
  let left = 0;
  for (let right = 0; right < inputs.length; right++) {
    if (inputs[right] === 0) countZero++;
    while (countZero > inputs[right]) {
      if (inputs[left++] === 0) countZero--;
    }
    maxLength = Math.max(maxLength, right - left + 1);
  }
  console.log(maxLength);
  rl.close();
}
In this code, we use two pointers `left` and `right` to maintain a window of zeros in the array. When we encounter a zero, we increase the count of zeros. If the count of zeros is greater than `K`, we move the left pointer to the right and decrease the count of zeros. We update the max length each time we find a longer window of zeros.