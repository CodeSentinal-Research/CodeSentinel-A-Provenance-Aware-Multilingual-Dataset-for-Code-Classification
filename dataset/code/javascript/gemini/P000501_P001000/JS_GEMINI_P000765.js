const fs = require('fs');
function isMaxHeap(arr, idx) {
    const n = arr.length;
    const l = 2 * idx + 1, r = 2 * idx + 2;
    if (l < n) {
        if (arr[idx] < arr[l] || !isMaxHeap(arr, l)) return false;
    }
    if (r < n) {
        if (arr[idx] < arr[r] || !isMaxHeap(arr, r)) return false;
    }
    return true;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        console.log(isMaxHeap(nums, 0) ? "true" : "false");
    }
}
main();