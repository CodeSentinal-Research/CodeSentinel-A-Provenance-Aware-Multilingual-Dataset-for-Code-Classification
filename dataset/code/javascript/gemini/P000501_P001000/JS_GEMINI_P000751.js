const fs = require('fs');
function countSubseqSum(arr, idx, curSum, target) {
    if (idx === arr.length) return curSum === target ? 1 : 0;
    return countSubseqSum(arr, idx + 1, curSum, target) + countSubseqSum(arr, idx + 1, curSum + arr[idx], target);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const target = parseInt(tokens[1 + n], 10);
        console.log(countSubseqSum(nums, 0, 0, target));
    }
}
main();