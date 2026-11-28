Here is the JavaScript code that would solve the given problem. The code uses a recursive approach to check for all possible partitions.

function canPartition(arr, n, k, curSum, curr, found) {
    // if we have found all partitions
    if (found == k) {
        return true;
    }
    // if we have not yet found all partitions and we have reached the end of the array
    if (curr == n) {
        return canPartition(arr, n, k, 0, 0, found + 1);
    }
    // if current sum exceeds the sum of the array, return false
    if (curSum > sum) {
        return false;
    }
    // include this number in the current partition
    if (canPartition(arr, n, k, curSum + arr[curr], curr + 1, found)) {
        return true;
    }
    // exclude this number from the current partition
    return canPartition(arr, n, k, curSum, curr + 1, found);
}

let readline = require('readline');
let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr = [];
rl.question('Enter numbers separated by space: ', function(input) {
    arr = input.split(' ').map(Number);
    rl.question('Enter value of K: ', function(input) {
        let k = Number(input);
        if (canPartition(arr, arr.length, k, 0, 0, 0)) {
            console.log('YES');
        } else {
            console.log('NO');
        }
        rl.close();
    });
});
In this code, we use a dynamic programming approach to solve the problem. The function `canPartition` checks whether a partition can be formed with the given conditions. If the sum of the partitioned array is equal, then we return true. If not, we continue to the next partition. If all partitions are found, then we return true. If we reach the end of the array, then we recurse with the next partition.