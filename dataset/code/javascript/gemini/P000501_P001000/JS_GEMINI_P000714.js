const fs = require('fs');
function subsetSum(arr, idx, curSum, res) {
    if (idx === arr.length) {
        res.push(curSum);
        return;
    }
    subsetSum(arr, idx + 1, curSum, res);
    subsetSum(arr, idx + 1, curSum + arr[idx], res);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const res = [];
        subsetSum(nums, 0, 0, res);
        res.sort((a, b) => a - b);
        console.log(res.join(' '));
    }
}
main();