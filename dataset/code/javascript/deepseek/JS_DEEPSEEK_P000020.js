function sumOfFirstNNaturalNumbers(n) {
  if (typeof n !== 'number' || !Number.isFinite(n) || !Number.isInteger(n) || n < 0) {
    throw new TypeError('Input must be a non-negative integer.');
  }
  // Arithmetic series formula: n(n+1)/2
  return (n * (n + 1)) / 2;
}