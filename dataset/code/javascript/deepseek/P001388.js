Here is a simple JavaScript solution using the sliding window technique to solve the problem:

function countDistinctElements(arr, k) {
  let distinctElements = new Map();
  let windowStart = 0;

  for (let windowEnd = 0; windowEnd < arr.length; windowEnd++) {
    if (distinctElements.has(arr[windowEnd])) {
      distinctElements.set(arr[windowEnd], distinctElements.get(arr[windowEnd]) + 1);
    } else {
      distinctElements.set(arr[windowEnd], 1);
    }

    if (windowEnd >= k - 1) {
      if (distinctElements.size === k) {
        console.log(distinctElements.size);
      }

      if (distinctElements.get(arr[windowStart]) === 1) {
        distinctElements.delete(arr[windowStart]);
      } else {
        distinctElements.set(arr[windowStart], distinctElements.get(arr[windowStart]) - 1);
      }

      windowStart++;
    }
  }
}

In this code, a `Map` is used to store the count of each element. The sliding window starts from the first element of the array and moves to the next element in each iteration, with the window size being `k`. For each window, it checks if the size of the distinct elements count is equal to `k` and if it is, it prints the count. If the window is not at the end of the array, it updates the count of the previous element and if the element being added to the window is already in the map, it increments the count. If the window is at the end of the array, it removes the previous element from the map.

Please note that this code assumes that `k` is an integer between 1 and the length of the array (inclusive), and that the array contains at least `k` distinct elements.