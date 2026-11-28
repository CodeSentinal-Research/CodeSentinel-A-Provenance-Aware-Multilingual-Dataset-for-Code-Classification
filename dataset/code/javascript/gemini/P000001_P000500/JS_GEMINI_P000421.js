const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const members = [];
        let idx = 1;
        for (let i = 0; i < n; i++) { members.push({id: tokens[idx], exp: tokens[idx+1]}); idx += 2; }
        const currDate = tokens[idx];
        members.filter(m => m.exp < currDate).forEach(m => console.log(m.id));
    }
}
main();