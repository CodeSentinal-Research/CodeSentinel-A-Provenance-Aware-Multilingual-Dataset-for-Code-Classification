const fs = require('fs');

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        let n = BigInt(input[0]);
        let sign = n < 0n ? -1n : 1n;
        let num = n < 0n ? -n : n;
        let rev = 0n;
        while (num > 0n) {
            rev = rev * 10n + (num % 10n);
            num /= 10n;
        }
        console.log((sign * rev).toString());
    }
}

main();