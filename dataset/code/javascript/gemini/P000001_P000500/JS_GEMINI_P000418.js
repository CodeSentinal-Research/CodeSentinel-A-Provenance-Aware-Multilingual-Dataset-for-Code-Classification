const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const emps = [];
        let idx = 1;
        for (let i = 0; i < n; i++) { emps.push({name: tokens[idx], date: tokens[idx+1]}); idx += 2; }
        const dateThresh = tokens[idx];
        emps.filter(e => e.date < dateThresh).forEach(e => console.log(e.name));
    }
}
main();