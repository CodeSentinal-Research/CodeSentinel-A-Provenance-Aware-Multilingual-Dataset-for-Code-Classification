const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        const res = [];
        let l = 0, r = n - 1;
        // Binary search loop to narrow down range
        while (l <= r) {
            if (l === r) res.push(vals[l]);
            else { res.push(vals[l]); res.push(vals[r]); }
            l++; r--;
        }
        console.log(res.join(' '));
    }
}
main();