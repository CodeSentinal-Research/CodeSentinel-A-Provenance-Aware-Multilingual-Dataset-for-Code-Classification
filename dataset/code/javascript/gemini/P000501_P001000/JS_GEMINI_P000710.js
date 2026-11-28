const fs = require('fs');
function perm(nums, cur, used) {
    if (cur.length === nums.length) {
        console.log(cur.join(' '));
        return;
    }
    for (let i = 0; i < nums.length; i++) {
        if (!used[i]) {
            used[i] = true;
            perm(nums, [...cur, nums[i]], used);
            used[i] = false;
        }
    }
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number).sort((a, b) => a - b);
        perm(nums, [], new Array(n).fill(false));
    }
}
main();