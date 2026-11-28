const fs = require('fs');
function genSubseq(arr, idx, cur) {
    if (idx === arr.length) {
        console.log(cur.join(' '));
        return;
    }
    genSubseq(arr, idx + 1, cur);
    genSubseq(arr, idx + 1, [...cur, arr[idx]]);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        genSubseq(nums, 0, []);
    }
}
main();