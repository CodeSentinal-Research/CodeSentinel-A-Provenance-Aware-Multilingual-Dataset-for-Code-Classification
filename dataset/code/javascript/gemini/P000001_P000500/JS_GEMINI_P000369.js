const fs = require('fs');

function main() {
    const lines = fs.readFileSync(0, 'utf-8').split(/\r?\n/);
    if (lines.length >= 1 && lines[0].trim() !== '') {
        const n = parseInt(lines[0].trim(), 10);
        const strings = lines.slice(1, n + 1);
        let idx = -1;
        for (let i = 0; i < n; i++) {
            if (strings[i] === '' && idx === -1) idx = i;
        }
        console.log(idx);
    }
}

main();