const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const n = parseInt(input[0], 10);
        const factors = [];
        for (let i = 1; i <= n; i++) if (n % i === 0) factors.push(i);
        console.log(factors.join(' '));
    }
}
main();