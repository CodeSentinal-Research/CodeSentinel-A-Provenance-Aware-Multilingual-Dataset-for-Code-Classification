const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const flights = [];
        let idx = 1;
        for (let i = 0; i < n; i++) {
            flights.push({flight: tokens[idx], dest: tokens[idx + 1]});
            idx += 2;
        }
        const target = tokens[idx];
        flights.filter(f => f.dest === target).forEach(f => console.log(f.flight));
    }
}

main();