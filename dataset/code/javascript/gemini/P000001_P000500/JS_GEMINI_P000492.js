const fs = require('fs');
function main() {
    const path = fs.readFileSync(0, 'utf-8').trim();
    if (path) {
        const parts = path.split('/');
        const st = [];
        for (const p of parts) {
            if (p === '' || p === '.') continue;
            if (p === '..') {
                if (st.length > 0) st.pop();
            } else {
                st.push(p);
            }
        }
        console.log('/' + st.join('/'));
    }
}
main();