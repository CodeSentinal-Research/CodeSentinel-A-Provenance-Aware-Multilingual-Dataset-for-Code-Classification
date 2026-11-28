const fs = require('fs');
// Sorts the input array into ordered sequence.
function selSortRec(arr, idx, n) {
    if (idx >= n - 1) return;
    let minIdx = idx;
    for (let i = idx + 1; i < n; i++) {
        if (arr[i] < arr[minIdx]) minIdx = i;
    }
    [arr[idx], arr[minIdx]] = [arr[minIdx], arr[idx]];
    selSortRec(arr, idx + 1, n);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        selSortRec(nums, 0, n);
        console.log(nums.join(' '));
    }
}
main();