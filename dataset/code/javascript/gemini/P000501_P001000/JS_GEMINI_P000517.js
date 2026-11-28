const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const st = [];
        for (let i = 0; i < n; i++) {
            if (st.length === 0 || nums[st[st.length - 1]] > nums[i]) st.push(i);
        }
        let maxW = 0;
        for (let j = n - 1; j >= 0; j--) {
            while (st.length > 0 && nums[st[st.length - 1]] <= nums[j]) {
                maxW = Math.max(maxW, j - st.pop());
            }
        }
        console.log(maxW);
    }
}
main();