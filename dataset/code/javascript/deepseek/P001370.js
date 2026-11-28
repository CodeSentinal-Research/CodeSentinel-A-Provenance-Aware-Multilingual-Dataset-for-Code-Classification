Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter a string: ', (string) => {
  rl.question('Enter K: ', (k) => {
    console.log(`Maximum number after ${k} swaps: ${getMaxNumber(string, k)}`);
    rl.close();
  });
});

function getMaxNumber(string, k) {
  let digits = Array.from(string, Number);
  digits.sort((a, b) => b - a);
  let map = {};
  for (let i = 0; i < digits.length; i++) {
    if (map[digits[i]]) {
      map[digits[i]].push(i);
    } else {
      map[digits[i]] = [i];
    }
  }
  let sortedDigits = Array.from({ length: digits.length }, () => -1);
  let count = 0;
  while (count < k) {
    let maxIndex = -1;
    for (let i = 0; i < digits.length; i++) {
      if (map[digits[i]] && map[digits[i]].length > 0) {
        let index = map[digits[i]].pop();
        sortedDigits[index] = digits[i];
        maxIndex = Math.max(maxIndex, index);
      }
    }
    if (maxIndex != -1) {
      digits[maxIndex] = digits[sortedDigits[maxIndex]];
      map[digits[maxIndex]] = [sortedDigits[maxIndex]];
      count++;
    } else {
      break;
    }
  }
  return digits.join('');
}

This code will read the string and K from the user, then print out the maximum number that can be obtained by at most K swaps. The swaps are performed in descending order (since we want to swap the maximum digit first), and the map is used to keep track of the index of each digit in the sorted array.