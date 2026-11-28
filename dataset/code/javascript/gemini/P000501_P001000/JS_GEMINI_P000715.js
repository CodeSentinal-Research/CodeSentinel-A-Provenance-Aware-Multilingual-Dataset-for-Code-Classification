const fs = require('fs');
function subsetsWithDup(nums, idx, cur) {
    console.log(cur.join(' '));
    for (let i = idx; i < nums.length; i++) {
        if (i > idx && nums[i] === nums[i - 1]) continue;
        subsetsWithDup(nums, i + 1, [...cur, nums[i]]);
    }
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number).sort((a, b) => a - b);
        subsetsWithDup(nums, 0, []);
    }
}
main();