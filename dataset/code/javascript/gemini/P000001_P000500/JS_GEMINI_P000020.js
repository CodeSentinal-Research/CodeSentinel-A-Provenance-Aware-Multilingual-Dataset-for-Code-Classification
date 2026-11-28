const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const n = BigInt(input[0]);
        const total = (n * (n + 1n)) / 2n;
        console.log(total.toString());
    }
}

main();