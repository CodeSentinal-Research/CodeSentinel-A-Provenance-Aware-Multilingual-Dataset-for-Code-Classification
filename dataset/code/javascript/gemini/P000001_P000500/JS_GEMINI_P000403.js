const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const trains = [];
        let idx = 1;
        for (let i = 0; i < n; i++) { trains.push({t: tokens[idx], s: tokens[idx+1]}); idx += 2; }
        const station = tokens[idx];
        trains.filter(x => x.s === station).forEach(x => console.log(x.t));
    }
}
main();