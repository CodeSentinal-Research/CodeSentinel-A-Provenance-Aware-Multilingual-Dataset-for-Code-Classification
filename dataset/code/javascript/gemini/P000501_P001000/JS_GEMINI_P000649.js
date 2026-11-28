const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const l1 = tokens.slice(1, 1 + n);
        const m = parseInt(tokens[1 + n], 10);
        const l2 = tokens.slice(2 + n, 2 + n + m);
        console.log((l1.length === l2.length && l1.every((v, i) => v === l2[i])) ? "true" : "false");
    }
}
main();