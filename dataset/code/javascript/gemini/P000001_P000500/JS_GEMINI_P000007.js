function checkEvenOrOdd(n) {
  if (typeof n === 'bigint') {
    return n % 2n === 0n ? 'Even' : 'Odd';
  }

  if (typeof n !== 'number' || !Number.isInteger(n)) {
    throw new TypeError('Input must be a valid integer.');
  }

  return n % 2 === 0 ? 'Even' : 'Odd';
}