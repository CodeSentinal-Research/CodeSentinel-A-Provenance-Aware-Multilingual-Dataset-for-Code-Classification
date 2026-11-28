const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const heights = tokens.slice(1, 1 + n).map(Number);
        const ans = new Array(n).fill(0);
        const st = [];
        // Process from right to left
        for (let i = n - 1; i >= 0; i--) {
            const h = heights[i];
            let count = 0;
            while (st.length > 0 && st[st.length - 1] < h) {
                st.pop();
                count++;
            }
            if (st.length > 0) count++;
            ans[i] = count;
            st.push(h);
        }
        console.log(ans.join(' '));
    }
}
main();