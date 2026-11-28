const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        const seen = new Set();
        const res = [];
        for (const x of vals) {
            if (!seen.has(x)) {
                seen.add(x);
                res.push(x);
            }
        }
        console.log(res.join(' '));
    }
}
main();