const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const s = input[0], c = input[1][0];
        let count = 0;
        for (const ch of s) if (ch === c) count++;
        console.log(count);
    }
}

main();