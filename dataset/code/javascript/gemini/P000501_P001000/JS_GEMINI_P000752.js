const fs = require('fs');
function findOneSubseq(arr, idx, cur, curSum, target) {
    if (idx === arr.length) {
        if (curSum === target && cur.length > 0) {
            console.log(cur.join(' '));
            return true;
        }
        return false;
    }
    if (findOneSubseq(arr, idx + 1, [...cur, arr[idx]], curSum + arr[idx], target)) return true;
    if (findOneSubseq(arr, idx + 1, cur, curSum, target)) return true;
    return false;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const target = parseInt(tokens[1 + n], 10);
        if (!findOneSubseq(nums, 0, [], 0, target)) {
            console.log(-1);
        }
    }
}
main();