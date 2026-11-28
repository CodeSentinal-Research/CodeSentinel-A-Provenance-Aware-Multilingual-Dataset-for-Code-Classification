const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const orders = [];
        let idx = 1;
        for (let i = 0; i < n; i++) { orders.push({id: tokens[idx], d: parseInt(tokens[idx+1], 10)}); idx += 2; }
        const days = parseInt(tokens[idx], 10);
        orders.filter(o => o.d > days).forEach(o => console.log(o.id));
    }
}
main();