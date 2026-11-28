const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const r = parseInt(tokens[0], 10), c = parseInt(tokens[1], 10);
        const mat = tokens.slice(2, 2 + r * c).map(Number);
        console.log(Math.max(...mat));
    }
}
main();