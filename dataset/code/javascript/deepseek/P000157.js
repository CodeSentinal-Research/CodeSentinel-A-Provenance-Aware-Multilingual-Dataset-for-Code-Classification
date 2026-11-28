Here's the JavaScript code to solve the problem:

process.stdin.on('data', (data) => {
  const N = parseInt(data, 10);
  const arr = process.stdin.read().toString().split(' ').map(x => parseInt(x, 10));
  
  const sum = arr.reduce((a, b) => a + b, 0);
  let leftSum = 0;
  
  for (let i = 0; i < N; i++) {
    if (leftSum === sum - leftSum - arr[i]) {
      console.log(i + 1);
      process.exit();
    }
    leftSum += arr[i];
  }
  
  console.log(-1);
});

In this code, we start by reading the first line as the number of elements in the array. We then read the next line as the array itself. We calculate the sum of the array and initialize two variables, `leftSum`, to keep track of the sum we've seen so far and `rightSum` to calculate the sum to the right of the current point. We then iterate over the array, checking if the sum of the left side equals the sum to the right minus the current element. If it does, we print the current point and exit. Otherwise, we add the current element to the `leftSum` and continue. If we reach the end of the array without finding an equilibrium point, we print -1.