const fs = require('fs');
// Performs search to locate target element within the given collection.
function binSearchRec(arr, target, l, r) {
    if (l > r) return -1;
    // Calculate midpoint to prevent potential overflow
    const mid = Math.floor((l + r) / 2);
    if (arr[mid] === target) return mid;
    if (arr[mid] > target) return binSearchRec(arr, target, l, mid - 1);
    return binSearchRec(arr, target, mid + 1, r);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const target = parseInt(tokens[1 + n], 10);
        console.log(binSearchRec(nums, target, 0, n - 1));
    }
}
main();