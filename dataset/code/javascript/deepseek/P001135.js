Here is the JavaScript code that solves the problem:

process.stdin.setEncoding('utf-8');
process.stdin.on('data', function(data) {
    let arr = data.split(' ').map(Number);
    console.log(findMaxSum(arr));
});

function findMaxSum(arr) {
    if(arr.length === 1) return arr[0];

    let excl = 0;
    let incl = arr[0];

    for(let i = 1; i < arr.length; i++) {
        let newExcl = Math.max(excl, incl);
        incl = excl + arr[i];
        excl = newExcl;
    }

    return Math.max(incl, excl);
}

This code reads the input data and then calls the function `findMaxSum` which finds the maximum sum of non-adjacent elements in an array. The `findMaxSum` function uses a dynamic programming approach to solve the problem. It iterates through the array and for each element, it calculates the maximum sum that can be obtained by excluding the current element (`excl`) and including the current element (`incl`). The `newExcl` is calculated as the maximum sum of the previous `excl` and `incl`, and `incl` is updated to be the sum of the current element and the previous `excl`. After the iteration, the maximum sum is returned as the answer.