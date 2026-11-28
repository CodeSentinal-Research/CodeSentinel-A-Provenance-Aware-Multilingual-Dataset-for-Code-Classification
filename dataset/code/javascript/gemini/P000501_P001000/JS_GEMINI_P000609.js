const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        let st = [];
        for (const x of vals) {
            st.push(x);
            let s = 0;
            for (let j = st.length - 1; j >= 0; j--) {
                s += st[j];
                if (s === 0) {
                    st = st.slice(0, j);
                    break;
                }
            }
        }
        console.log(st.join(' '));
    }
}
main();