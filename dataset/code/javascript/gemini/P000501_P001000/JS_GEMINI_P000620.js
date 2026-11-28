const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const bits = tokens.slice(1, 1 + n).join('');
        console.log(parseInt(bits, 2));
    }
}
main();