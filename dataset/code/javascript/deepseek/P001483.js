const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let lines = [];
rl.on('line', (line) => {
    lines.push(line);
    if (lines.length == 2) {
        processLines(lines);
        rl.close();
    }
});

function processLines(lines) {
    let [N, K] = lines[0].split(' ').map(Number);
    let binaryArray = lines[1].split(' ').map(Number);

    let left = 0, right = 0;
    let zeroCount = 0;
    let maxLength = 0;

    while (right < N) {
        if (binaryArray[right] == 0) {
            zeroCount++;
        }

        while (zeroCount > K) {
            if (binaryArray[left] == 0) {
                zeroCount--;
            }
            left++;
        }

        maxLength = Math.max(maxLength, right - left + 1);

        right++;
    }

    console.log(maxLength);
}

This JavaScript code reads the input line by line using the readline module. The first line of input is processed into the variables N and K. The second line of input is an array of binary integers, which is processed directly.

The code uses two pointers, left and right, to track the window of ones in the array. It maintains a count of zeroes in the window and uses a while loop to move the left pointer to the right if the count of zeroes exceeds K. It also updates the maximum length found so far.

The code runs in O(N) time complexity as it only iterates over the array once. The space complexity is O(1) as it only uses a fixed amount of space to store the variables left, right, zeroCount and maxLength.