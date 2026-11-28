const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const a = input[0], b = input[1];
        console.log(a === b ? -1 : Math.max(a.length, b.length));
    }
}

main();