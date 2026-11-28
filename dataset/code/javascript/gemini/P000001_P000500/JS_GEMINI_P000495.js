const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const q = parseInt(tokens[0], 10);
        const prices = tokens.slice(1, 1 + q).map(Number);
        const st = [];
        for (const price of prices) {
            let span = 1;
            while (st.length > 0 && st[st.length - 1].price <= price) {
                span += st.pop().span;
            }
            st.push({price, span});
            console.log(span);
        }
    }
}
main();