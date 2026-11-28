const fs = require('fs');
function revArrRec(arr, l, r) {
    if (l >= r) return;
    [arr[l], arr[r]] = [arr[r], arr[l]];
    revArrRec(arr, l + 1, r - 1);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        revArrRec(nums, 0, n - 1);
        console.log(nums.join(' '));
    }
}
main();