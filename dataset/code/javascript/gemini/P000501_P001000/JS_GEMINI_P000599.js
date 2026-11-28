const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        const counts = new Map();
        for (const x of vals) counts.set(x, (counts.get(x) || 0) + 1);
        const res = vals.filter(x => counts.get(x) === 1);
        console.log(res.join(' '));
    }
}
main();