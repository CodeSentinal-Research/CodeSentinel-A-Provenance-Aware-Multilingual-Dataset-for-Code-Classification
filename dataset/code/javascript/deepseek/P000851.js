function setKthBit(N, K) {
  if (K < 0 || K > 31 || typeof N !== 'number' || typeof K !== 'number') {
    throw new Error('Invalid input');
  }

  return N | (1 << K);
}