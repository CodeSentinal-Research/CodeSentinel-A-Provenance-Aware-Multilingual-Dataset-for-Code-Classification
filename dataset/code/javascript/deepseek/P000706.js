Here's the JavaScript code for generating all binary strings of length N using recursion.

function generateBinStrings(n) {
  if (n === 0) {
    return [''];
  } else if (n === 1) {
    return ['0', '1'];
  }

  const result = [];

  const leftStrings = generateBinStrings(n - 1);

  for (const leftString of leftStrings) {
    for (let bit of [0, 1]) {
      result.push(bit.toString() + leftString);
    }
  }

  return result;
}

const n = 3; // input
const binStrings = generateBinStrings(n);
binStrings.sort();
console.log(binStrings);

This code first checks if the length of the string is 0 or 1. If it is, it returns the string of that length. If it is 2, it returns the two strings '0' and '1'. If the length is more than 2, it generates all binary strings of length n - 1 using recursion and then for each binary string, it appends 0 or 1 to the beginning. It sorts the results and logs them to the console.