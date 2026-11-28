const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const docs = [];
        let idx = 1;
        for (let i = 0; i < n; i++) { docs.push({d: tokens[idx], s: tokens[idx+1]}); idx += 2; }
        const spec = tokens[idx];
        docs.filter(x => x.s === spec).forEach(x => console.log(x.d));
    }
}
main();