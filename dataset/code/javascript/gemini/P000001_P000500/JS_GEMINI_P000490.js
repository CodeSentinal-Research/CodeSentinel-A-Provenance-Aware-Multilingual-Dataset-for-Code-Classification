const fs = require('fs');
function process(s) {
    const st = [];
    for (const c of s) {
        if (c === '#') {
            if (st.length > 0) st.pop();
        } else {
            st.push(c);
        }
    }
    return st.join('');
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const s = tokens[0];
        const t = tokens.length > 1 ? tokens[1] : '';
        console.log(process(s) === process(t) ? "true" : "false");
    }
}
main();