const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const s = tokens[tokens.length - 1];
        const words = tokens.slice(0, tokens.length - 1);
        let count = 0;
        for (const w of words) {
            if (s.startsWith(w)) count++;
        }
        console.log(count);
    }
}

main();