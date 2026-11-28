const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const products = [];
        let idx = 1;
        for (let i = 0; i < n; i++) {
            products.push({name: tokens[idx], price: parseFloat(tokens[idx + 1])});
            idx += 2;
        }
        const minP = parseFloat(tokens[idx]);
        const maxP = parseFloat(tokens[idx + 1]);
        products.filter(p => p.price >= minP && p.price <= maxP).forEach(p => console.log(p.name));
    }
}

main();