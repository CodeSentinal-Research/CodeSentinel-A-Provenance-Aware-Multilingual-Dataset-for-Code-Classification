const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const inp = tokens.slice(1, 1 + n).map(Number);
        const out = tokens.slice(1 + n, 1 + 2 * n).map(Number);
        const st = [];
        let j = 0;
        for (const x of inp) {
            st.push(x);
            while (st.length > 0 && j < n && st[st.length - 1] === out[j]) {
                st.pop();
                j++;
            }
        }
        console.log(j === n ? "true" : "false");
    }
}
main();