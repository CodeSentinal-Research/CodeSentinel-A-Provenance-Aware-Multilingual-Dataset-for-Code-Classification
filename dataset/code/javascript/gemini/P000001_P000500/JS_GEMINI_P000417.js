const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const books = [];
        let idx = 1;
        for (let i = 0; i < n; i++) { books.push({title: tokens[idx], author: tokens[idx+1], genre: tokens[idx+2]}); idx += 3; }
        const a = tokens[idx], g = tokens[idx+1];
        books.filter(b => b.author === a && b.genre === g).forEach(b => console.log(b.title));
    }
}
main();