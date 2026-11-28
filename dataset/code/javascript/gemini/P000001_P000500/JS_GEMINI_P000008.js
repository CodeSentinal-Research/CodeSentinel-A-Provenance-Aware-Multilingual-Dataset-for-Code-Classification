function checkNumber(n) {
  const num = Number(n);

  if (Number.isNaN(num)) {
    throw new TypeError('Input must be a valid number');
  }

  if (num > 0) {
    return 'Positive';
  }
  if (num < 0) {
    return 'Negative';
  }
  return 'Zero';
}