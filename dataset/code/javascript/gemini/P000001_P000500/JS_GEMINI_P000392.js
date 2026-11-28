const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const files = tokens.slice(1, n + 1);
        let ext = tokens[n + 1];
        if (!ext.startsWith('.')) ext = '.' + ext;
        files.filter(f => f.endsWith(ext)).forEach(f => console.log(f));
    }
}

main();