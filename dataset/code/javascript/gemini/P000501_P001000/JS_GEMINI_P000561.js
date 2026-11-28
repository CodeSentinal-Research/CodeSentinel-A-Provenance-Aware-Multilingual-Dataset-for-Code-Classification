const fs = require('fs');
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) {
        const count = {};
        const q = [];
        let res = "";
        for (const c of s) {
            count[c] = (count[c] || 0) + 1;
            q.push(c);
            while (q.length > 0 && count[q[0]] > 1) q.shift();
            res += q.length > 0 ? q[0] : '#';
        }
        console.log(res);
    }
}
main();