const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const expr = tokens.slice(1, 1 + n);
        const st = [];
        for (const token of expr) {
            if (['+', '-', '*', '/'].includes(token)) {
                const b = st.pop();
                const a = st.pop();
                if (token === '+') st.push(a + b);
                else if (token === '-') st.push(a - b);
                else if (token === '*') st.push(a * b);
                else if (token === '/') st.push(Math.trunc(a / b));
            } else {
                st.push(parseInt(token, 10));
            }
        }
        console.log(st[0]);
    }
}
main();