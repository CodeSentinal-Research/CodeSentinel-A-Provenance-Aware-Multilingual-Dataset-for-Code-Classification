Here is a JavaScript solution for the problem. It constructs a prefix sum array by using a loop to iterate through the input array and build the prefix sum array:

function prefixSum(nums) {
  let prefixSumArray = [];
  let sum = 0;

  for (let i = 0; i < nums.length; i++) {
    sum += nums[i];
    prefixSumArray.push(sum);
  }

  return prefixSumArray;
}

This code defines a function named `prefixSum` that accepts an array of integers. It then creates an empty array, `prefixSumArray`, and a variable, `sum`, to keep track of the running sum.

The code then iterates over the input array. In each iteration, it adds the current element to the `sum` and pushes the new sum into the `prefixSumArray`.

Finally, it returns the constructed `prefixSumArray`.

To use this function, you would pass in the input array to it:

console.log(prefixSum([1, 2, 3, 4, 5])); // [1, 3, 6, 10, 15]