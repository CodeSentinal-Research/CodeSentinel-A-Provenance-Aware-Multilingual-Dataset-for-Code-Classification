Here is the JavaScript code that will solve the problem:

function solve(arr) {
    // Sort the array in ascending order
    arr.sort((a, b) => a - b);

    let minDiff = Infinity;
    let pairs = [];

    // Loop through the array to find pairs with minimum difference
    for (let i = 0; i < arr.length - 1; i++) {
        const diff = Math.abs(arr[i] - arr[i + 1]);
        if (diff < minDiff) {
            minDiff = diff;
            // Store all pairs with this minimum difference
            pairs = [[arr[i], arr[i + 1]]];
        } else if (diff === minDiff) {
            // Store this pair in our pairs array
            pairs.push([arr[i], arr[i + 1]]);
        }
    }

    // Print all pairs with minimum difference
    pairs.forEach((pair) => {
        console.log(`${pair[0]} ${pair[1]}`);
    });
}

// Sample usage
console.log(`Enter numbers separated by space:`);
const arrStr = readline();
const arr = arrStr.split(' ').map(Number);
solve(arr);

In this code, we first sort the array in ascending order. Then we loop through the sorted array and find all pairs with the minimum difference. If we find a pair with a smaller difference than the current minimum difference, we store it. If we find a pair with the same difference, we store it. Finally, we print all pairs with the minimum difference.

Please note that this code requires a function `readline` to read the input from the console. If you're using Node.js, you can use `require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
})` to read from the console. If you're not using Node.js, you'll need to implement this yourself.