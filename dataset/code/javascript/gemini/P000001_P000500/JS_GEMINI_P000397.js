const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const orders = [];
        let idx = 1;
        for (let i = 0; i < n; i++) {
            orders.push({id: tokens[idx], status: tokens[idx + 1]});
            idx += 2;
        }
        const target = tokens[idx];
        orders.filter(o => o.status === target).forEach(o => console.log(o.id));
    }
}

main();