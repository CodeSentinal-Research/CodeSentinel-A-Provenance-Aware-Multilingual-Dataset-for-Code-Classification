const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        for (let i = 0; i + 1 < n; i += 2) {
            [vals[i], vals[i + 1]] = [vals[i + 1], vals[i]];
        }
        console.log(vals.join(' '));
    }
}
main();