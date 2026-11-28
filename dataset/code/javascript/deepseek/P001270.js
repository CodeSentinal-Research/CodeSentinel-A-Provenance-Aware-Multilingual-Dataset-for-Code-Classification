Here is the JavaScript code for the problem:

// Reading inputs
var input = require('fs').readFileSync('stdin', 'utf8');
var N = Number(input.split('\n')[0]);
var arr = input.split('\n')[1].split(' ').map(Number);

// Initialize operations count
var operations = 0;

// Sort the array in decreasing order
arr.sort(function(a, b){return b - a});

// Iterate through the sorted array
for(var i = 0; i < N; i++){
    // If the current element is greater than the current index
    if(arr[i] > i){
        // Subtract the difference from the current element to 0
        operations += arr[i] - i - 1;
    }
    else{
        // If the current element is 0, break the loop
        break;
    }
}

// Print the minimum operations
console.log(operations);

This script reads the input array and then sorts it in descending order. Then it iterates through the sorted array, subtracting the absolute difference from the current element to 0 for each positive element. If the current element is 0, it breaks the loop. The total operations are then printed to the console.