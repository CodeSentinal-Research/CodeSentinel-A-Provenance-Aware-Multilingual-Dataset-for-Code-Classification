Here is the JavaScript code to solve the given problem.

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let cases = Number(rl.readline()); // reading the test cases
rl.on('close', () => {
  process.exit();
});

while(cases--) {
  let input = rl.readline().split(' ').map(Number);
  let arr = input[0];
  let k = input[1];
  let map = new Map();
  let result = false;

  for(let i = 0; i < arr.length; i++) {
    if(map.has(arr[i])) {
      if(Math.abs(i - map.get(arr[i])) <= k) {
        result = true;
        break;
      } else {
        map.set(arr[i], i);
      }
    } else {
      map.set(arr[i], i);
    }
  }

  if(result) {
    console.log('YES');
  } else {
    console.log('NO');
  }
}
In this code, we are reading the test cases from the console input. We are iterating through each case. Inside the case, we are reading the array and K from the input and initializing a map to store the array elements. We are then iterating through the array and checking if the current element is already present in the map or not. If it is, we are checking if the difference between the index of current element and the value stored in the map is less than or equal to K. If it is, we break the loop and print 'YES'. If it's not, we are adding the current element and its index to the map. If the current element is not present in the map, we are adding it. Finally, if no pair of elements satisfy the condition, we print 'NO'.