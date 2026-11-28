const fs = require('fs');
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) {
        const st = [];
        for (const c of s) {
            if (st.length > 0 && Math.abs(st[st.length - 1].charCodeAt(0) - c.charCodeAt(0)) === 32) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        console.log(st.join(''));
    }
}
main();