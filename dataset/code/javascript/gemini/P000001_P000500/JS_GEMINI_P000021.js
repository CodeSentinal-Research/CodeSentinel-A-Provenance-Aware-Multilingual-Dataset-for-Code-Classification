const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const n = parseInt(input[0], 10);
        let fact = 1n;
        for (let i = 2n; i <= BigInt(n); i++) {
            fact *= i;
        }
        console.log(fact.toString());
    }
}

main();