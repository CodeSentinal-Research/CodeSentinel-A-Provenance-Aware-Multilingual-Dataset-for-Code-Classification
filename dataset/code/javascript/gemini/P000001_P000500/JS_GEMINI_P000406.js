const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const movies = [];
        let idx = 1;
        for (let i = 0; i < n; i++) { movies.push({m: tokens[idx], g: tokens[idx+1]}); idx += 2; }
        const genre = tokens[idx];
        movies.filter(x => x.g === genre).forEach(x => console.log(x.m));
    }
}
main();