const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const cars = [];
        let idx = 1;
        for (let i = 0; i < n; i++) {
            cars.push({p: parseFloat(tokens[idx]), s: parseFloat(tokens[idx+1])});
            idx += 2;
        }
        const ans = new Array(n).fill(-1.0);
        const st = [];
        // Process from right to left
        for (let i = n - 1; i >= 0; i--) {
            while (st.length > 0) {
                const j = st[st.length - 1];
                if (cars[i].s <= cars[j].s || (ans[j] > 0 && (cars[j].p - cars[i].p) / (cars[i].s - cars[j].s) >= ans[j])) {
                    st.pop();
                } else {
                    break;
                }
            }
            if (st.length > 0) {
                const j = st[st.length - 1];
                ans[i] = (cars[j].p - cars[i].p) / (cars[i].s - cars[j].s);
            }
            st.push(i);
        }
        console.log(ans.map(x => x.toFixed(5)).join(' '));
    }
}
main();