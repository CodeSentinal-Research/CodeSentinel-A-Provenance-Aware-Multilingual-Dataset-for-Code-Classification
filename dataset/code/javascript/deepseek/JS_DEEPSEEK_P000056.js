function sumSeries(N) {
  if (typeof N !== 'number' || !isFinite(N)) {
    return 0;
  }
  const n = Math.floor(N);
  if (n < 1) {
    return 0;
  }
  return n * (n + 1) / 2;
}