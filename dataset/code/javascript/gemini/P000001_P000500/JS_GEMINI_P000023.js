const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const n = parseInt(input[0], 10);
        const fib = [];
        let a = 0n, b = 1n;
        for (let i = 0; i < n; i++) {
            fib.push(a.toString());
            const next = a + b;
            a = b;
            b = next;
        }
        console.log(fib.join(" "));
    }
}

main();