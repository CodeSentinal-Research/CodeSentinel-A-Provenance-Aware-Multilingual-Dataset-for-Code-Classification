const fs = require('fs');
// Sorts the input array into ordered sequence.
function isSortedRec(arr, idx) {
    if (idx >= arr.length - 1) return true;
    if (arr[idx] > arr[idx + 1]) return false;
    return isSortedRec(arr, idx + 1);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        console.log(isSortedRec(nums, 0) ? "true" : "false");
    }
}
main();