const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const num = tokens[0];
        let k = parseInt(tokens[1], 10);
        const st = [];
        for (const c of num) {
            while (k > 0 && st.length > 0 && st[st.length - 1] > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }
        while (k > 0 && st.length > 0) {
            st.pop();
            k--;
        }
        const res = st.join('').replace(/^0+/, '');
        console.log(res ? res : "0");
    }
}
main();