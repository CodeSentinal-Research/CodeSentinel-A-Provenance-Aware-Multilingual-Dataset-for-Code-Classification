const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const k = parseInt(tokens[1 + n], 10);
        const q = [];
        const ans = [];
        for (let i = 0; i < n; i++) {
            while (q.length > 0 && q[0] < i - k + 1) q.shift();
            while (q.length > 0 && nums[q[q.length - 1]] <= nums[i]) q.pop();
            q.push(i);
            if (i >= k - 1) ans.push(nums[q[0]]);
        }
        console.log(ans.join(' '));
    }
}
main();