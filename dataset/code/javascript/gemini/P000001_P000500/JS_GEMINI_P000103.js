const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const n = parseInt(input[0], 10);
        let total = 0n;
        for (let i = 1; i <= n; i++) total += BigInt(input[i]);
        console.log(total.toString());
    }
}
main();