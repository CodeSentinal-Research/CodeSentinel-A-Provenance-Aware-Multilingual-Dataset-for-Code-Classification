const fs = require('fs');
function genKStrings(chars, k, cur) {
    if (cur.length === k) {
        console.log(cur);
        return;
    }
    for (const c of chars) {
        genKStrings(chars, k, cur + c);
    }
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const chars = tokens.slice(1, 1 + n).sort();
        const k = parseInt(tokens[1 + n], 10);
        genKStrings(chars, k, "");
    }
}
main();