const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const events = [];
        let idx = 1;
        for (let i = 0; i < n; i++) { events.push({name: tokens[idx], date: tokens[idx+1]}); idx += 2; }
        const date = tokens[idx];
        events.filter(e => e.date === date).forEach(e => console.log(e.name));
    }
}
main();