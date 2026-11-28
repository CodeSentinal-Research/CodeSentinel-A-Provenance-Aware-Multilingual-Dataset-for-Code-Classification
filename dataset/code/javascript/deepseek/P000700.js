Here is the JavaScript code for finding the maximum element in an array using recursion.

function findMax(nums, n) {
    if (n === 1) {
        return Math.max(nums[0], nums[1]);
    } else {
        let max = findMax(nums, n - 1);
        return Math.max(max, nums[n - 1]);
    }
}

let nums = [1, 3, 2, 7, 5];
let n = nums.length;
console.log(findMax(nums, n)); // Output: 7

In this code, we are defining a recursive function `findMax` that takes an array and its size as parameters. If the size is 1, it simply returns the max of the first two elements. If the size is more than 1, it recursively calls `findMax` on the first `n-1` elements of the array (as we are looking for the `max`, not the `n-th` element) and the last element of the array. It then compares the `max` of these two recursive calls and the last element of the array, and returns the larger of the two.

The final line of the code is an example of how to use this function. It creates an array of integers and then logs the maximum element to the console.