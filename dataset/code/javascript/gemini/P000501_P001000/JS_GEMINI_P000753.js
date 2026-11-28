const fs = require('fs');
function findAllSubseq(arr, idx, cur, curSum, target, res) {
    if (idx === arr.length) {
        if (curSum === target && cur.length > 0) res.push(cur);
        return;
    }
    findAllSubseq(arr, idx + 1, cur, curSum, target, res);
    findAllSubseq(arr, idx + 1, [...cur, arr[idx]], curSum + arr[idx], target, res);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const target = parseInt(tokens[1 + n], 10);
        const res = [];
        findAllSubseq(nums, 0, [], 0, target, res);
        res.sort((a, b) => {
            for (let i = 0; i < Math.min(a.length, b.length); i++) {
                if (a[i] !== b[i]) return a[i] - b[i];
            }
            return a.length - b.length;
        });
        for (const seq of res) console.log(seq.join(' '));
    }
}
main();