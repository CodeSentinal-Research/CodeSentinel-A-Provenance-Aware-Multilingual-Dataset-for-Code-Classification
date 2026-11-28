const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const a = BigInt(input[0]), b = BigInt(input[1]);
        console.log(a % b === 0n ? "Divisible" : "Not Divisible");
    }
}
main();