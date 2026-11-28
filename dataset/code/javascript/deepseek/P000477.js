Here is the JavaScript code for your problem:

// Read the number of elements and elements of array from input
let [n, ...inputs] = require('fs').readFileSync('./stdin.txt', 'utf-8').split('\n').map(Number);

let findPivotIndex = (nums) => {
    let leftSum = 0;
    let rightSum = nums.reduce((a, b) => a + b, 0);

    for(let i = 0; i < nums.length; i++) {
        rightSum -= nums[i];

        if(leftSum === rightSum) {
            return i;
        }

        leftSum += nums[i];
    }

    return -1;
}

console.log(findPivotIndex(inputs));

This code first reads the number of elements and the elements from input. It then defines a function `findPivotIndex` that finds the pivot index in a rotated sorted array. The `findPivotIndex` function calculates the sum of all elements in the array and the sum of all elements to the left of each element. It then iterates through the array, each time subtracting the current element from the sum of all elements to the right and adding the current element to the sum of all elements to the left. If the sum of all elements to the right is equal to the sum of all elements to the left, it returns the current index. If no pivot index is found, it returns -1. Finally, it logs the result of the `findPivotIndex` function to the console.