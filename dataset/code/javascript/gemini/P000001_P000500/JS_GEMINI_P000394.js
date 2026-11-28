const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const products = [];
        let idx = 1;
        for (let i = 0; i < n; i++) {
            products.push({name: tokens[idx], brand: tokens[idx + 1]});
            idx += 2;
        }
        const targetBrand = tokens[idx];
        products.filter(p => p.brand === targetBrand).forEach(p => console.log(p.name));
    }
}

main();