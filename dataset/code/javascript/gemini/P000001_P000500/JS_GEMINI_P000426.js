const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const rests = [];
        let idx = 1;
        for (let i = 0; i < n; i++) { rests.push({name: tokens[idx], rating: parseFloat(tokens[idx+1])}); idx += 2; }
        const thresh = parseFloat(tokens[idx]);
        rests.filter(r => r.rating >= thresh).forEach(r => console.log(r.name));
    }
}
main();