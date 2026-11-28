process.stdin.resume();
process.stdin.on('data', (chunk) => {
  const N = parseInt(chunk.toString().trim());

  const arr = process.stdin.read().toString().split(' ').map(num => parseInt(num)).slice(0, N);

  console.log(maxSubarraySumCircular(arr));

  process.stdin.pause();
});

function maxSubarraySumCircular(arr) {
  let maxSum = Math.max(...arr);
  if (maxSum < 0) return maxSum; // if all numbers are negative

  // Kadane's algorithm
  let currentMax = 0, globalMax = arr[0];
  for (let i = 0; i < arr.length; i++) {
    currentMax = Math.max(arr[i], currentMax + arr[i]);
    globalMax = Math.max(globalMax, currentMax);
  }

  // If all numbers are negative, return the max negative number
  if (globalMax < 0) return globalMax;

  // Compute the total sum of the array
  let totalSum = 0;
  for (let i = 0; i < arr.length; i++) {
    totalSum += arr[i];
  }

  // Return the max circular subarray sum
  return Math.max(globalMax, totalSum - globalMax);
}