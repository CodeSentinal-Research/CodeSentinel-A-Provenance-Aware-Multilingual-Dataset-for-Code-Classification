Here is the JavaScript code that handles the input and solves the problem:

let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = parseInt(rl.question());
let arr1 = rl.question().split(' ').map(Number);
let arr2 = rl.question().split(' ').map(Number);

function minOperations(arr1, arr2, N) {
    let operations = 0;
    for(let i = 0; i < N; i++) {
        operations += Math.max(arr1[i], arr2[i]) - arr1[i];
        arr1[i] = Math.max(arr1[i], arr2[i]);
    }
    return operations;
}

console.log(minOperations(arr1, arr2, N));
This code will ask for the input from the user and then call the minOperations function with the input arrays and the number of elements to perform the operation. The minOperations function then calculates the minimum number of operations required to make the prefix sums of both arrays the same. It does this by iterating over the elements of both arrays, and for each element, it increments the element in the first array by the difference between the current element in the second array and the element in the first array. After each operation, it updates the element in the first array to be the maximum of the two elements. It then returns the total number of operations required.