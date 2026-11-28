const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        const k = parseInt(tokens[1 + n], 10);
        const width = Math.floor(n / k), rem = n % k;
        let cur = 0;
        for (let i = 0; i < k; i++) {
            const sz = width + (i < rem ? 1 : 0);
            if (sz === 0) {
                console.log("[]");
            } else {
                console.log(vals.slice(cur, cur + sz).join(' '));
                cur += sz;
            }
        }
    }
}
main();