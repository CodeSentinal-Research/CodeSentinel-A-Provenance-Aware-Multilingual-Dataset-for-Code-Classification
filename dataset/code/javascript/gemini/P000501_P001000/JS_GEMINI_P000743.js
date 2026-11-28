const fs = require('fs');
// Sorts the input array into ordered sequence.
function bubbleSortRec(arr, n) {
    if (n <= 1) return;
    for (let i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            [arr[i], arr[i + 1]] = [arr[i + 1], arr[i]];
        }
    }
    bubbleSortRec(arr, n - 1);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        bubbleSortRec(nums, n);
        console.log(nums.join(' '));
    }
}
main();