process.stdin.resume();
process.stdin.on('data', function(chunk) {
  var n = chunk.toString().trim();
  var arr = process.stdin.read().toString().trim().split(' ').map(Number);

  function minProductSubarray(arr, n) {
    let product = arr[0];
    let minProduct = arr[0];
    let maxProduct = arr[0];
    let result = arr[0];

    for(let i = 1; i < n; i++) {
        if(arr[i] < 0) {
            let temp = maxProduct;
            maxProduct = minProduct;
            minProduct = temp;
        }

        maxProduct = Math.max(arr[i], maxProduct * arr[i]);
        minProduct = Math.min(arr[i], minProduct * arr[i]);

        result = Math.min(result, minProduct);
    }

    return result;
  }

  console.log(minProductSubarray(arr, n));
});
This program reads input as an array of integers, calculates the minimum product of any contiguous subarray, and then prints the result. It handles negative numbers correctly because it swaps minProduct and maxProduct if the current number is negative. maxProduct and minProduct are updated based on the current number and the max and min product found till now. The result is updated only if the minProduct is less than the current result.