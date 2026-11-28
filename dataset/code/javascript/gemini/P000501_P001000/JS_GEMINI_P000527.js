const fs = require('fs');
// Calculates modular exponentiation (base^exp % mod) efficiently.
function parseBoolExpr(expression) {
    const st = [];
    for (const c of expression) {
        if (c === ',' || c === '(') continue;
        if (['t', 'f', '!', '&', '|'].includes(c)) {
            st.push(c);
        } else if (c === ')') {
            let seenT = false, seenF = false;
            while (st.length > 0 && (st[st.length - 1] === 't' || st[st.length - 1] === 'f')) {
                const val = st.pop();
                if (val === 't') seenT = true;
                if (val === 'f') seenF = true;
            }
            const op = st.pop();
            if (op === '!') st.push(seenT ? 'f' : 't');
            else if (op === '&') st.push(seenF ? 'f' : 't');
            else if (op === '|') st.push(seenT ? 't' : 'f');
        }
    }
    return st[0] === 't';
}
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) console.log(parseBoolExpr(s) ? "true" : "false");
}
main();