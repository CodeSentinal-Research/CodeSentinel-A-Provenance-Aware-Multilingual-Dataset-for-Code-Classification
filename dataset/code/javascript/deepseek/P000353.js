function findLastOccurrence(N, arr, X) {
  for (let i = arr.length - 1; i >= 0; i--) {
    if (arr[i] === X) {
      return i;
    }
  }
  return -1;
}