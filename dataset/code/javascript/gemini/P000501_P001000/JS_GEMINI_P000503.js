const fs = require('fs');
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) {
        const st = [0];
        for (const c of s) {
            if (c === '(') {
                st.push(0);
            } else {
                const v = st.pop();
                st[st.length - 1] += Math.max(2 * v, 1);
            }
        }
        console.log(st[0]);
    }
}
main();