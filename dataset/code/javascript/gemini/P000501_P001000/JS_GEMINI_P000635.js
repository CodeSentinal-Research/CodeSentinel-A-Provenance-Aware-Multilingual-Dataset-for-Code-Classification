const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 3 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        const g = parseInt(tokens[1 + n], 10);
        const groups = tokens.slice(2 + n, 2 + n + g).map(Number);
        let cur = 0;
        for (const sz of groups) {
            if (cur + sz <= n) {
                const sub = vals.slice(cur, cur + sz).reverse();
                vals.splice(cur, sz, ...sub);
                cur += sz;
            } else {
                break;
            }
        }
        console.log(vals.join(' '));
    }
}
main();