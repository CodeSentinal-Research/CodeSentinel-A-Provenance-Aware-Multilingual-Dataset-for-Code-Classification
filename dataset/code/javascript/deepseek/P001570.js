Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N;
rl.question('Enter the number of elements: ', (n) => {
  N = parseInt(n);
  const nums = [];
  rl.setEncoding('utf-8');
  rl.question('Enter the numbers: ', (line) => {
    const numbers = line.split(' ');
    for(let i = 0; i < N; i++) {
      nums[i] = parseInt(numbers[i]);
    }
    console.log(getMaxLength(nums));
    rl.close();
  });
});

function getMaxLength(arr) {
  let left = 0, right = 0, maxLen = 0;
  let product = 1;

  while (right < arr.length) {
    product *= arr[right];

    while (product < 0) {
      product /= arr[left];
      left++;
    }

    maxLen = Math.max(maxLen, right - left + 1);
    right++;
  }

  return maxLen;
}

This script reads the number of elements N and the list of numbers from the standard input. It then calls a function `getMaxLength()` to find the maximum length of a subarray with positive product. The function uses two pointers (left and right) to track the start and end of the subarray, and uses a variable `product` to store the product of the elements in the subarray. It then enters a loop that continues until the right pointer is at the end of the array. Inside the loop, it multiplies the product by the next element (`arr[right]`) and updates the product if it becomes negative. If the product becomes negative, it divides it by the element at the start (`arr[left]`) and then increments the left pointer. It also updates the maximum length if necessary. Finally, it increments the right pointer and continues the loop.