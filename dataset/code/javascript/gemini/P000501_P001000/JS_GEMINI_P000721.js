const fs = require('fs');
function findSubseq(nums, idx, cur, res) {
    if (cur.length >= 2) res.set(cur.join(','), cur);
    for (let i = idx; i < nums.length; i++) {
        if (cur.length === 0 || nums[i] >= cur[cur.length - 1]) {
            findSubseq(nums, i + 1, [...cur, nums[i]], res);
        }
    }
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const res = new Map();
        findSubseq(nums, 0, [], res);
        const list = Array.from(res.values()).sort((a, b) => {
            for (let i = 0; i < Math.min(a.length, b.length); i++) {
                if (a[i] !== b[i]) return a[i] - b[i];
            }
            return a.length - b.length;
        });
        for (const seq of list) console.log(seq.join(' '));
    }
}
main();