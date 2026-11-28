/*
Reverse a number in any base
Note
The function should return an integer.
The base b will be greater or equal to 1.
Edge case: Base-1 is also used in this kata to represent the unary numeral system. Think of it as a system of tally marks. For example:
3 (decimal) -> ||| (unary)
5 (decimal) -> ||||| (unary)

*/

const reverseNumber = (num, base) => {
  if (base === 1n) return num;

  let result = 0n;

  while (num > 0n) {
      const digit = num % base;
      result = result * base + digit;
      num /= base;
  }

  return result;
};