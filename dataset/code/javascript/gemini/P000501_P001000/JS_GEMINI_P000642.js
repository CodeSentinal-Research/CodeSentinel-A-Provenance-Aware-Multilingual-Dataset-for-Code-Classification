const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 3 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        const pos = parseInt(tokens[1 + n], 10);
        const val = parseInt(tokens[2 + n], 10);
        vals.splice(pos, 0, val);
        console.log(vals.join(' '));
    }
}
main();