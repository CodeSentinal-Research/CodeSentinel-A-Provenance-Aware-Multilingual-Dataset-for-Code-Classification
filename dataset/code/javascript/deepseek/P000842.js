function solve(n, index, maxSum) {
  if (n > maxSum || index > n) {
    return "Invalid input";
  }
  
  let arr = new Array(n).fill(1).map((_, i) => i + 1);
  let sum = arr.reduce((a, b) => a + b, 0);
  let left = sum - arr[index];
  
  if (left <= maxSum) {
    return arr[index];
  } else {
    return Math.max(arr[index], arr[index + 1]);
  }
}