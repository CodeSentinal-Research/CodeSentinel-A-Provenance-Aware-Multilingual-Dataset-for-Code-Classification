const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 3 && tokens[0] !== '') {
        const size = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + size).map(Number);
        const m = parseInt(tokens[1 + size], 10);
        const n = parseInt(tokens[2 + size], 10);
        const res = [];
        let cur = 0;
        while (cur < size) {
            res.push(...vals.slice(cur, cur + m));
            cur += m + n;
        }
        console.log(res.join(' '));
    }
}
main();