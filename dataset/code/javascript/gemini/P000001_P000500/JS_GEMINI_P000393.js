const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const names = tokens.slice(1, n + 1);
        const prefix = tokens[n + 1];
        names.filter(name => name.startsWith(prefix)).forEach(name => console.log(name));
    }
}

main();