const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const accs = [];
        let idx = 1;
        for (let i = 0; i < n; i++) { accs.push({acc: tokens[idx], m: parseInt(tokens[idx+1], 10)}); idx += 2; }
        const months = parseInt(tokens[idx], 10);
        accs.filter(a => a.m >= months).forEach(a => console.log(a.acc));
    }
}
main();