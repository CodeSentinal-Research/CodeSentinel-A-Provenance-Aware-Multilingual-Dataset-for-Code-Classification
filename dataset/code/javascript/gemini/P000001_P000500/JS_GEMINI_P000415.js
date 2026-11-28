const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const patients = [];
        let idx = 1;
        for (let i = 0; i < n; i++) { patients.push({p: tokens[idx], bg: tokens[idx+1]}); idx += 2; }
        const blood = tokens[idx];
        patients.filter(x => x.bg === blood).forEach(x => console.log(x.p));
    }
}
main();