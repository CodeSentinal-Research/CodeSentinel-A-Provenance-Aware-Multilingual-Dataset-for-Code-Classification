const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const ops = tokens.slice(1, n + 1);
        const st = [];
        for (const op of ops) {
            if (op === '+') st.push(st[st.length - 1] + st[st.length - 2]);
            else if (op === 'D') st.push(st[st.length - 1] * 2);
            else if (op === 'C') st.pop();
            else st.push(parseInt(op, 10));
        }
        console.log(st.reduce((a, b) => a + b, 0));
    }
}
main();