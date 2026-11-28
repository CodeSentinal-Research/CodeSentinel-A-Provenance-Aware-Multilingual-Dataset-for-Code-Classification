const fs = require('fs');
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) {
        const st = [];
        for (const c of s) {
            if (c === '*') {
                if (st.length > 0) st.pop();
            } else {
                st.push(c);
            }
        }
        console.log(st.join(''));
    }
}
main();