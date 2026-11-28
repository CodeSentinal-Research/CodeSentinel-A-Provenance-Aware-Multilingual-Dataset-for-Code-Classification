function sumOfDigits(L, R) {
  let sum = 0;
  for (let i = L; i <= R; i++) {
    let digits = i.toString().split('');
    for (let j = 0; j < digits.length; j++) {
      sum += parseInt(digits[j]);
    }
  }
  return sum;
}

console.log(sumOfDigits(1, 2)); // Example usage

In the provided code, the function sumOfDigits takes two parameters L and R. It starts by initializing a sum variable to 0. Then it starts a loop from L to R (inclusive). For each number in the range, it converts the number into a string, splits that string into an array of characters (digits), and then converts each character back into a number. It then adds this number to the sum. At the end of the function, it returns the sum of the digits.