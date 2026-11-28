const fs = require('fs');
// Sorts the input array into ordered sequence.
function insSortRec(arr, n) {
    if (n <= 1) return;
    insSortRec(arr, n - 1);
    const last = arr[n - 1];
    let j = n - 2;
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        insSortRec(nums, n);
        console.log(nums.join(' '));
    }
}
main();