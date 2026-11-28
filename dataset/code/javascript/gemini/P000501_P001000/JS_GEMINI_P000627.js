const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        const k = parseInt(tokens[1 + n], 10);
        const res = [];
        for (let i = 0; i < n; i += k) {
            const chunk = vals.slice(i, i + k);
            if (chunk.length === k) res.push(...chunk.reverse());
            else res.push(...chunk);
        }
        console.log(res.join(' '));
    }
}
main();