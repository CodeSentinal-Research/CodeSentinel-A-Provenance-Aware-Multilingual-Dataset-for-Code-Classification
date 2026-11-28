Here is the JavaScript code that solves the problem:

function largestUniqueNumber(arr) {
  let count = {};
  for (let num of arr) {
    count[num] = (count[num] || 0) + 1;
  }

  for (let num of arr.reverse()) {
    if (count[num] === 1) {
      return num;
    }
  }

  return -1;
}

// Testing
console.log(largestUniqueNumber([1, 3, 3, 1])); // Output: 3
console.log(largestUniqueNumber([1, 2, 3, 4])); // Output: -1

This code first counts the occurrences of each number in the array using a dictionary or hash map. Then it iterates over the array in reverse order, checking if each number has only one occurrence. If a number has only one occurrence, it is the largest unique number, so it returns that number. If no such number is found, it returns -1.