const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const songs = [];
        let idx = 1;
        for (let i = 0; i < n; i++) { songs.push({s: tokens[idx], a: tokens[idx+1]}); idx += 2; }
        const artist = tokens[idx];
        songs.filter(x => x.a === artist).forEach(x => console.log(x.s));
    }
}
main();