const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const ans = new Array(n).fill(-1);
        const st = [];
        for (let i = 0; i < 2 * n; i++) {
            const val = nums[i % n];
            while (st.length > 0 && nums[st[st.length - 1]] < val) {
                const prev = st.pop();
                ans[prev] = val;
            }
            if (i < n) st.push(i);
        }
        console.log(ans.join(' '));
    }
}
main();