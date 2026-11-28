const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const q = parseInt(tokens[0], 10);
        let idx = 1;
        const st = [];
        for (let i = 0; i < q; i++) {
            const cmd = tokens[idx];
            if (cmd === 'push') {
                st.push(parseInt(tokens[idx+1], 10));
                idx += 2;
            } else if (cmd === 'pop') {
                if (st.length > 0) console.log(st.pop());
                idx += 1;
            } else if (cmd === 'top') {
                if (st.length > 0) console.log(st[st.length - 1]);
                idx += 1;
            } else if (cmd === 'empty') {
                console.log(st.length === 0 ? "true" : "false");
                idx += 1;
            }
        }
    }
}
main();