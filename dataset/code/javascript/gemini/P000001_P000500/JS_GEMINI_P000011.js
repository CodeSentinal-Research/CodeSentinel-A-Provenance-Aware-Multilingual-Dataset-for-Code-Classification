const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 3) {
        const a = parseInt(input[0], 10);
        const b = parseInt(input[1], 10);
        const c = parseInt(input[2], 10);
        console.log(Math.max(a, b, c));
    }
}

main();