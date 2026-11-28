// Read input
let [n, arr] = require('fs').readFileSync('input.txt', 'utf8').split('\n').map(parseFloat);

let left = 0;
let right = 0;
let sum = arr[0];
let maxSum = sum;

while (right < n - 1) {
    if (sum - arr[left] >= arr[right + 1]) {
        sum -= arr[left];
        left++;
    } else if (sum + arr[right + 1] >= arr[right + 1]) {
        sum += arr[right + 1];
        right++;
    } else {
        sum = arr[right + 1];
        left = right = right + 1;
    }

    if (sum > maxSum) {
        maxSum = sum;
    }
}

console.log(maxSum);