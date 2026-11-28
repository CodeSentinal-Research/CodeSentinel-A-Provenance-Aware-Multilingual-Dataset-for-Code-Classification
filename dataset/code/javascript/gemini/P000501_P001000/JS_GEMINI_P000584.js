const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const size = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + size).map(Number);
        const n = parseInt(tokens[1 + size], 10);
        vals.splice(size - n, 1);
        console.log(vals.join(' '));
    }
}
main();