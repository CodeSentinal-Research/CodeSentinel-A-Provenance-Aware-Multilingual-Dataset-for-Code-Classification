const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const prods = [];
        let idx = 1;
        for (let i = 0; i < n; i++) { prods.push({name: tokens[idx], price: parseFloat(tokens[idx+1])}); idx += 2; }
        const minP = parseFloat(tokens[idx]);
        prods.filter(p => p.price >= minP).forEach(p => console.log(p.name));
    }
}
main();