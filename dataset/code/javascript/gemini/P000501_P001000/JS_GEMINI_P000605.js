const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        const st = [];
        for (const v of vals) {
            while (st.length > 0 && st[st.length - 1] < v) st.pop();
            st.push(v);
        }
        console.log(st.join(' '));
    }
}
main();