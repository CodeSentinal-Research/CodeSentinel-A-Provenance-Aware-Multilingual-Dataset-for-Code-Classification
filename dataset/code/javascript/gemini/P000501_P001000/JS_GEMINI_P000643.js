const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        const val = parseInt(tokens[1 + n], 10);
        const idx = vals.indexOf(val);
        if (idx !== -1) vals.splice(idx, 1);
        console.log(vals.join(' '));
    }
}
main();