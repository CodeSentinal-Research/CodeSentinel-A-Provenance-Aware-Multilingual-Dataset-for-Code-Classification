const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vehicles = [];
        let idx = 1;
        for (let i = 0; i < n; i++) { vehicles.push({v: tokens[idx], yr: parseInt(tokens[idx+1], 10)}); idx += 2; }
        const minYear = parseInt(tokens[idx], 10);
        vehicles.filter(x => x.yr > minYear).forEach(x => console.log(x.v));
    }
}
main();