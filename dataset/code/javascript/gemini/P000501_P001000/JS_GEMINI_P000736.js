const fs = require('fs');
function kthGrammar(n, k) {
    if (n === 1) return 0;
    const parent = kthGrammar(n - 1, Math.floor((k + 1) / 2));
    if (parent === 0) return k % 2 !== 0 ? 0 : 1;
    else return k % 2 !== 0 ? 1 : 0;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        console.log(kthGrammar(parseInt(tokens[0], 10), parseInt(tokens[1], 10)));
    }
}
main();