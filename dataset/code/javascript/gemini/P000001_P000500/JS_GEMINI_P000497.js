const fs = require('fs');
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) {
        const lastOcc = {};
        for (let i = 0; i < s.length; i++) lastOcc[s[i]] = i;
        const seen = new Set();
        const st = [];
        for (let i = 0; i < s.length; i++) {
            const c = s[i];
            if (!seen.has(c)) {
                while (st.length > 0 && st[st.length - 1] > c && i < lastOcc[st[st.length - 1]]) {
                    seen.delete(st.pop());
                }
                seen.add(c);
                st.push(c);
            }
        }
        console.log(st.join(''));
    }
}
main();