function countSubarrays(arr, k) {
  const n = arr.length;
  let res = 0;

  // Iterate through the array
  for (let i = 0; i < n; i++) {
    let distinctCount = 0;
    let countMap = {};

    // Iterate through the subarray starting from i
    for (let j = i; j < n; j++) {
      // If the element is not in the map, add it
      if (!countMap[arr[j]]) {
        distinctCount++;
        countMap[arr[j]] = true;
      }

      // If the distinct count reaches k, break the inner loop
      if (distinctCount === k) {
        break;
      }
    }

    // If the distinct count is k, increment the result
    if (distinctCount === k) {
      res++;
    }
  }

  return res;
}

// Test the function
console.log(countSubarrays([1, 2, 3, 4], 2));  // Outputs: 3
console.log(countSubarrays([1, 2, 3, 4], 1));  // Outputs: 4
This JavaScript function `countSubarrays` counts the number of contiguous subarrays in the input array with exactly `k` distinct elements.

The function iterates through the array, for each element, it iterates through the subarray starting from the current element. It keeps a map (object in JavaScript) to count the distinct elements in the subarray. The map uses the element as the key and the value as `true`. If the distinct element count (`distinctCount`) reaches `k`, it breaks the inner loop.

If the distinct element count is `k`, it increments the result. After iterating through the entire array, it returns the result.

The time complexity of this function is `O(n^2)`, where `n` is the length of the input array. This is due to the nested loop structure of the function. The space complexity is `O(n)`, as in the worst case, the space used by the map can grow up to `n`.