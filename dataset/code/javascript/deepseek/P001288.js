Here's a simple JavaScript code to solve the problem. The code takes two inputs, an array of integers and a number K. It then sorts the array in descending order and negates the sign of one element every K times. At the end, it prints the maximum sum of the array.

function maxSumAfterNeg(arr, K) {
    // Sort the array in descending order
    arr.sort((a, b) => b - a);

    // Iterate through the array
    for (let i = 0; i < arr.length; i++) {
        // If K is zero, return the sum
        if (K === 0) {
            let sum = 0;
            for (let j = 0; j < arr.length; j++) {
                sum += arr[j];
            }
            return sum;
        }
        // If the current element is less than the next one, negate it
        if (arr[i] < arr[i + 1]) {
            arr[i + 1] = -arr[i + 1];
            K--;
        }
        // If K becomes zero, return the sum
        if (K === 0) {
            return arr.reduce((a, b) => a + b, 0);
        }
    }
}

console.log(maxSumAfterNeg([1,2,3,4,5,6,7,8,9,10], 3));

This code assumes that the input array will not contain negative numbers. If the array can contain negative numbers, you'll need to add a check to handle that.