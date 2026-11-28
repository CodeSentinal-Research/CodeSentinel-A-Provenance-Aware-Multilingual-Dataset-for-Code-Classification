const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const c = parseFloat(input[0]);
        const f = (c * 9.0 / 5.0) + 32.0;
        console.log(f);
    }
}

main();