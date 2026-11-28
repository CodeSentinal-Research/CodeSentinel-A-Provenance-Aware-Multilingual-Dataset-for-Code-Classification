Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = 0;

rl.on('line', function(line) {
    N = parseInt(line);
});

let array = [];

rl.on('line', function(line) {
    array.push(parseInt(line));
    if (array.length === N) rl.close();
});

rl.on('close', function() {
    function moveZerosToEnd(arr) {
        let i = 0, j = arr.length - 1;
        while (i < j) {
            if (arr[i] !== 0) {
                i++;
            } else if (arr[j] === 0) {
                j--;
            } else {
                [arr[i], arr[j]] = [arr[j], arr[i]];
                i++;
                j--;
            }
        }
        return arr;
    }

    console.log(moveZerosToEnd(array).join(' '));

    process.exit();
});
This code reads the number N and then the array of integers. It then uses a while loop to move all zeros to the end while maintaining the order of the non-zero elements.