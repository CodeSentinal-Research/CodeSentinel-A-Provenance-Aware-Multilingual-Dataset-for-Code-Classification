Here is the JavaScript code:

function intToRoman(num) {
  if (isNaN(num)) {
    throw new Error("Input must be a number");
  }
  if (num < 1 || num > 3999) {
    throw new Error("Input must be between 1 and 3999");
  }

  const ints = [1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000];
  const roman = ['I', 'IV', 'V', 'IX', 'X', 'XL', 'L', 'XC', 'C', 'CD', 'D', 'CM', 'M'];

  let romanStr = '';

  for (let i = 13; i >= 0; i--) {
    while (num >= ints[i]) {
      num -= ints[i];
      romanStr += roman[i];
    }
  }

  return romanStr;
}
This code first checks if the input is a number and if it is within the valid range (1-3999). If the input is not a number or is not within the valid range, an error is thrown.

Then it uses a loop to subtract the largest possible Roman numeral value from the input number and appends the corresponding Roman numeral to the result string. This process continues until the input number is zero. The result is the Roman numeral representation of the input number.