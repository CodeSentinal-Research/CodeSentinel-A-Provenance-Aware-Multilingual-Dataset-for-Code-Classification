Here is the JavaScript code:

function searchNegativeNumber(N, arr) {
  for (let i = 0; i < N; i++) {
    if (arr[i] < 0) {
      return i;
    }
  }
  return -1;
}

This function takes two parameters: an integer N and an array of integers. It iterates through the array, and when it encounters a negative number, it returns the index of that number. If it doesn't find any negative number, it returns -1.