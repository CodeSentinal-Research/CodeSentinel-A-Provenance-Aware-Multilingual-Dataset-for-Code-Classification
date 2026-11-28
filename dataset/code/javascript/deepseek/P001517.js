Here is the code:

process.stdin.resume();
process.stdin.on('data', (chunk) => {
  const N = parseInt(chunk.toString().trim());
  const arr = process.stdin.read().toString().trim().split(' ').map(num => parseInt(num)).sort((a, b) => a - b);
  let maxSum = 0;

  for (let i = 0; i < N / 2; i++) {
    maxSum += Math.max(arr[i], arr[N - i - 1]);
  }

  console.log(maxSum);
  process.stdin.pause();
});
This program first reads the number of elements N, then reads the array of integers. It then sorts the array in ascending order. The program then iterates through the array in pairs (first and last element of each pair), calculates the sum of the pair and updates the maxSum variable. After all pairs have been iterated through, the maxSum is printed to the console.