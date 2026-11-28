const fs = require('fs');
// Sorts the input array into ordered sequence.
function quickSort(arr, l, r) {
    if (l >= r) return;
    const pivot = arr[r];
    let pIdx = l;
    for (let i = l; i < r; i++) {
        if (arr[i] < pivot) {
            [arr[i], arr[pIdx]] = [arr[pIdx], arr[i]];
            pIdx++;
        }
    }
    [arr[pIdx], arr[r]] = [arr[r], arr[pIdx]];
    quickSort(arr, l, pIdx - 1);
    quickSort(arr, pIdx + 1, r);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        quickSort(nums, 0, n - 1);
        console.log(nums.join(' '));
    }
}
main();