const fs = require('fs');
function countOccRec(arr, target, idx) {
    if (idx >= arr.length) return 0;
    return (arr[idx] === target ? 1 : 0) + countOccRec(arr, target, idx + 1);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const target = parseInt(tokens[1 + n], 10);
        console.log(countOccRec(nums, target, 0));
    }
}
main();