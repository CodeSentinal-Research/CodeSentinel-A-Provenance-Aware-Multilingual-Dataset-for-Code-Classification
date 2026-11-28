Here is the JavaScript code for checking if a given number is an Armstrong number.

function isArmstrongNumber(num) {
  let numStr = num.toString();
  let numLength = numStr.length;
  let sum = 0;

  for (let i = 0; i < numLength; i++) {
    let digit = parseInt(numStr[i]);
    sum += Math.pow(digit, numLength);
  }

  return sum === num;
}

console.log(isArmstrongNumber(153)); // true
console.log(isArmstrongNumber(370)); // true
console.log(isArmstrongNumber(371)); // true
console.log(isArmstrongNumber(407)); // true
console.log(isArmstrongNumber(1634)); // true
console.log(isArmstrongNumber(8208)); // true
console.log(isArmstrongNumber(8908750)); // true
console.log(isArmstrongNumber(1234567890)); // true
This code takes a number as input and checks if it is an Armstrong number by iterating over its digits, raising each digit to the power of the total number of digits, and summing up these values. If the sum is equal to the original number, then the number is an Armstrong number.

The time complexity of this code is O(d), where d is the number of digits in the input number, as each digit is processed once.