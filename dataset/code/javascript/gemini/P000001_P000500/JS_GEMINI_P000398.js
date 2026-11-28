const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vehicles = [];
        let idx = 1;
        for (let i = 0; i < n; i++) {
            vehicles.push({name: tokens[idx], manuf: tokens[idx + 1]});
            idx += 2;
        }
        const target = tokens[idx];
        vehicles.filter(v => v.manuf === target).forEach(v => console.log(v.name));
    }
}

main();