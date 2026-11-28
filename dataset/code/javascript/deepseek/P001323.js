Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let testCases = Number(rl.question(''));
rl.close();

while(testCases-- > 0){
  let input = rl.readline('').toString().split(' ').map(Number);
  let nums = input[0], target = input[1];
  let result = findCombination(nums, target);
  console.log(result);
}

function findCombination(arr, target) {
  let result = [];
  arr.sort((a, b) => a - b);
  backtrack(arr, target, 0, [], result);
  return result;
}

function backtrack(nums, target, start, path, result) {
  if (target < 0) {
    return;
  }
  if (target === 0) {
    result.push(path.slice());
    return;
  }
  for (let i = start; i < nums.length; i++) {
    if (i > start && nums[i] === nums[i - 1]) {
      continue;
    }
    path.push(nums[i]);
    backtrack(nums, target - nums[i], i + 1, path, result);
    path.pop();
  }
}

This code uses backtracking to find all combinations of numbers that sum up to the target. The main idea is to use a recursive function to try all possible combinations. If the sum of the current combination is greater than the target, we can stop further exploration. If the sum is equal to the target, we found a valid combination, so we add it to the result array. If the sum is less than the target, we add each number to the current combination and continue the exploration. In the end, we print the result.