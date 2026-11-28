const fs = require('fs');
function numTrees(n) {
    let c = 1n;
    for (let i = 0n; i < BigInt(n); i++) {
        c = c * 2n * (2n * i + 1n) / (i + 2n);
    }
    return c;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        console.log(numTrees(parseInt(tokens[0], 10)).toString());
    }
}
main();