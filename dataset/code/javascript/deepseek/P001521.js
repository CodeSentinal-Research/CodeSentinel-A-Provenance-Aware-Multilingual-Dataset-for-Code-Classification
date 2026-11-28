Here is a JavaScript solution for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of elements: ', (n) => {
    rl.question('Enter elements separated by space: ', (input) => {
        const arr = input.split(' ').map(Number);
        console.log(maxChunksToMakeSortedII(arr, n));
        rl.close();
    });
});

function maxChunksToMakeSortedII(arr, n) {
    let max = -1, chunks = 0;
    const rightMax = new Array(n).fill(0);
    rightMax[n - 1] = arr[n - 1];
    for(let i = n - 2; i >= 0; i--) {
        rightMax[i] = Math.max(rightMax[i + 1], arr[i]);
    }
    for(let i = 0; i < n - 1; i++) {
        max = Math.max(max, arr[i]);
        if(max <= rightMax[i + 1]) {
            chunks++;
        }
    }
    return chunks;
}

In this code, we first read the number of elements and the elements themselves from the standard input. We then call the `maxChunksToMakeSortedII` function with the input array and number of elements as arguments.

The function `maxChunksToMakeSortedII` calculates the maximum value to the right of each index in the array, and then checks if the current maximum value is less than or equal to the next element in the array. If it is, we increment the chunks count. We continue this process until we have checked all the elements in the array.

The `max` variable is used to keep track of the maximum value we have seen so far, and the `chunks` variable is used to count the number of chunks. The `rightMax` array is used to store the maximum value to the right of each index in the array.

The time complexity of the code is O(n), and the space complexity is also O(n), as we are storing a new array of size n.