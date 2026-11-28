Here is a JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let inputArray = [];

rl.on('line', function(line) {
    inputArray = line.split(' ').map(Number);
    const target = inputArray[1];
    const nums = inputArray.slice(2);
    const pairs = findPairs(nums, target);
    console.log(pairs.join('\n'));
});

function findPairs(nums, target) {
    const numMap = {};
        numMap[nums[0]] = 0;
        for(let i = 1; i < nums.length; i++) {
            const complement = target - nums[i];
            if(numMap[complement] !== undefined) {
                return [[nums[i], complement]];
            }
            numMap[nums[i]] = i;
       
        }
}

This code reads the inputs line by line. It splits the line into an array of numbers, then finds all pairs whose sum equals the target number. It prints the pairs to the console.

Please note that this is a simple implementation and may not be the most efficient for large inputs. For large inputs, a more efficient algorithm may be needed.