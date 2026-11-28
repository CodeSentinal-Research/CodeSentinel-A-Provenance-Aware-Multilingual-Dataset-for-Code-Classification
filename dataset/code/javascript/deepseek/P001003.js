Here is the JavaScript code that finds the minimum element in a given min heap:

function findMin(arr, i, n) {
  // If there is only one element in the array
  if (i == n - 1) {
    return arr[i];
  }

  // If the first element is greater than the last element,
  // then the array is not min heap.
  if (arr[i] > arr[i + 1]) {
    return arr[i + 1];
  }

  // Else recur for the subarray from index 1 to n-1.
  return findMin(arr, i + 1, n);
}

function main() {
  let arr = process.argv[2].split(' ').map(Number);
  let n = arr.shift();
  console.log(findMin(arr, 0, n));
}

main();

In this code, we are passing the input from the command line as a string, splitting it into an array, and then mapping it to a numeric array. The main function is where we call the findMin function. This function recursively calls itself until it finds the minimum element.

To use this code, you would call it from the command line like this: `node filename.js "5 2 1 3 6 5"`.

Please note that this code assumes that the input is a string that can be parsed into an array of integers. If the input is not valid, it may not work as expected.