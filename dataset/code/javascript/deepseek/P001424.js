Here is the JavaScript code for the problem:

// read input from console
const input = require('fs').readFileSync('/dev/stdin', 'utf8');
const lines = input.split('\n');

// get number of elements and elements themselves
const N = parseInt(lines[0]);
const arr = lines[1].split(' ').map(Number);

// create a frequency map
const map = {};
for (const num of arr) {
  if (map[num]) {
    map[num]++;
  } else {
    map[num] = 1;
  }
}

// check if all frequencies are unique
const frequencies = Object.values(map);
const uniqueFrequencies = [...new Set(frequencies)];
if (uniqueFrequencies.length === frequencies.length) {
  console.log('YES');
} else {
  console.log('NO');
}

This code reads the number of elements N and the elements themselves from the input. It then counts the frequency of each number in the array and checks if all frequencies are unique. If all frequencies are unique, it outputs 'YES', otherwise it outputs 'NO'.