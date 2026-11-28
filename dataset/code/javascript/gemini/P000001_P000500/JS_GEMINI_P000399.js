const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const books = [];
        let idx = 1;
        for (let i = 0; i < n; i++) {
            books.push({title: tokens[idx], year: parseInt(tokens[idx + 1], 10)});
            idx += 2;
        }
        const minYear = parseInt(tokens[idx], 10);
        books.filter(b => b.year > minYear).forEach(b => console.log(b.title));
    }
}

main();