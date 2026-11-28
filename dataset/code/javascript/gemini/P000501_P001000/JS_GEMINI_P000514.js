const fs = require('fs');
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) {
        const st = [];
        for (let i = s.length - 1; i >= 0; i--) {
            const c = s[i];
            if (st.length > 0 && st[st.length - 1] === '?') {
                st.pop(); // '?'
                const first = st.pop();
                st.pop(); // ':'
                const second = st.pop();
                st.push(c === 'T' ? first : second);
            } else {
                st.push(c);
            }
        }
        console.log(st[0]);
    }
}
main();