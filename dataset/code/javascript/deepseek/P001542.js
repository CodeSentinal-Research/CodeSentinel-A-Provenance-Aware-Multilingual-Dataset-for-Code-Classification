let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let lines = input.split('\n');
let n = parseInt(lines[0].split(' ')[0]);
let k = parseInt(lines[0].split(' ')[1]);
let arr = lines[1].split(' ').map(Number);

function averageOfWindows(arr, k) {
    let i = 0;
    while (i < arr.length - k + 1) {
        let sum = 0;
        for (let j = i; j < i + k; j++) {
            sum += arr[j];
        }
        console.log(sum / k);
        i++;
   
    }
}

averageOfWindows(arr, k);

In this code, we read the input in an array, and then we calculate the average of every subarray of size K in the input array. The `averageOfWindows` function calculates the sum of every subarray and prints the average. The `while` loop iterates over the array, and `for` loop calculates the sum of each subarray. The `i` variable is used to skip elements in the subarray as it iterates over them.