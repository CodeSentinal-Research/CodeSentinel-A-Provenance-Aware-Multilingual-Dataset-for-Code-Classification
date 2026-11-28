const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = new Set(tokens.slice(1, 1 + n).map(Number));
        const target = parseInt(tokens[1 + n], 10);
        console.log(vals.has(target) ? "true" : "false");
    }
}
main();