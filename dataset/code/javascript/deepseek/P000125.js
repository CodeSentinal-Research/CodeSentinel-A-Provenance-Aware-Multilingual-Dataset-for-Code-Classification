Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N;
rl.question('Enter the number of elements N: ', (N) => {
  rl.question('Enter the target value: ', (target) => {
    let inputArray = [];
    rl.setPrompt('Enter ' + N + ' integers: ');
    rl.prompt();

    inputArray = inputArray.map(Number);
    rl.close();

    let result = findTwoSum(inputArray, target);

    console.log('The two indices are: ' + result);
  });
});

function findTwoSum(array, target) {
  let map = new Map();
  for(let i = 0; i < array.length; i++) {
    if(map.has(target - array[i])) {
      return [map.get(target - array[i]), i];
    } else {
      map.set(array[i], i);
    }
  }
  return [];
}

In this program, we use a map to store the differences between the target and the current number. If the difference is already in the map, we return the indices of the current number and the difference. If not, we add the current number and its index to the map.