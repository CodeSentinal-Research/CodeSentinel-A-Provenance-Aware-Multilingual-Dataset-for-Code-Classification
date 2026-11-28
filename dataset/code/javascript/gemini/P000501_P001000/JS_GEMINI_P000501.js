const fs = require('fs');
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) {
        const st = [];
        for (const c of s) {
            if (c === ')') {
                const temp = [];
                while (st.length > 0 && st[st.length - 1] !== '(') {
                    temp.push(st.pop());
                }
                st.pop();
                st.push(...temp);
            } else {
                st.push(c);
            }
        }
        console.log(st.join(''));
    }
}
main();