const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const prices = tokens.slice(1, 1 + n).map(Number);
        const ans = [...prices];
        const st = [];
        for (let i = 0; i < n; i++) {
            while (st.length > 0 && prices[st[st.length - 1]] >= prices[i]) {
                const prev = st.pop();
                ans[prev] -= prices[i];
            }
            st.push(i);
        }
        console.log(ans.join(' '));
    }
}
main();