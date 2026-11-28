Here is the JavaScript code for the problem:

var _ = require('lodash');

process.stdin.resume();
process.stdin.on('data', function(data){
    var N = parseInt(data.toString().trim());
    var arr = process.stdin.read().toString().split(' ').map(Number);
    console.log(countPivotIndices(arr, N));
});

function countPivotIndices(arr, N) {
    let leftSum = 0;
    let rightSum = _.sum(arr);
    let count = 0;

    for(let i = 0; i < N; i++) {
        rightSum -= arr[i];
        if(leftSum === rightSum) {
            count++;
        }
        leftSum += arr[i];
    }
    return count;
}

In this code, the first line of input is taken as the number of elements in the array. The second line contains the elements of the array. The countPivotIndices function is defined to count the number of pivot indices in the array. It first initializes the sum of left and right half of the array, and the count of pivot indices. Then, it iterates over the array, each time it subtracts the current element from the right sum and checks if it's equal to the left sum. If it is, it increments the count. After each iteration, it adds the current element from the left sum. The function returns the count of pivot indices.