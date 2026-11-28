Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = 0;
rl.question('Enter the number of elements: ', (N) => {
    let binaryArray = [];
    rl.setPrompt('Enter binary integer: ');
    rl.prompt()
    .then(input => {
        binaryArray = input.split(' ');
        let maxLen = findMaxLength(binaryArray);
        console.log(maxLen);
        rl.close();
    })
    .catch(e => {
        console.log('Error:', e);
        rl.close();
    });
});

function findMaxLength(arr) {
    let map = new Map();
    let sum = 0;
    let maxLen = 0;
    map.set(0, -1);
    for (let i = 0; i < arr.length; i++) {
        sum += arr[i] === '1' ? 1 : -1;
        if (!map.has(sum)) {
            map.set(sum, i);
        } else {
            maxLen = Math.max(maxLen, i - map.get(sum));
        }
    }
    return maxLen;
}

This code first reads the number of elements `N` from user input and then reads `N` binary integers. It then calls a function `findMaxLength` which finds the length of the longest subarray with equal number of 0s and 1s. The function uses a Map to store the sum of the elements. If the sum is not present in the Map, it stores the sum and its index. If the sum is present in the Map, it checks the maximum length and updates the maximum length if the current length is greater. Finally, it returns the maximum length.