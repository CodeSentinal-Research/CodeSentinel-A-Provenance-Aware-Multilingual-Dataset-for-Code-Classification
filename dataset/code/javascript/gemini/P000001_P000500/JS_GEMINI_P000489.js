const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const q = parseInt(tokens[0], 10);
        let idx = 1;
        const st = [], minSt = [];
        for (let i = 0; i < q; i++) {
            const cmd = tokens[idx];
            if (cmd === 'push') {
                const val = parseInt(tokens[idx+1], 10);
                st.push(val);
                minSt.push(minSt.length === 0 ? val : Math.min(val, minSt[minSt.length - 1]));
                idx += 2;
            } else if (cmd === 'pop') {
                if (st.length > 0) { st.pop(); minSt.pop(); }
                idx += 1;
            } else if (cmd === 'top') {
                if (st.length > 0) console.log(st[st.length - 1]);
                idx += 1;
            } else if (cmd === 'getMin') {
                if (minSt.length > 0) console.log(minSt[minSt.length - 1]);
                idx += 1;
            }
        }
    }
}
main();