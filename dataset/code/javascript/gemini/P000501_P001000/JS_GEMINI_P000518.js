const fs = require('fs');
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) {
        const st = [-1];
        let maxLen = 0;
        for (let i = 0; i < s.length; i++) {
            if (s[i] === '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.length === 0) {
                    st.push(i);
                } else {
                    maxLen = Math.max(maxLen, i - st[st.length - 1]);
                }
            }
        }
        console.log(maxLen);
    }
}
main();