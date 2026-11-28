const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const products = tokens.slice(1, n + 1);
        const suffix = tokens[n + 1];
        products.filter(p => p.endsWith(suffix)).forEach(p => console.log(p));
    }
}
main();