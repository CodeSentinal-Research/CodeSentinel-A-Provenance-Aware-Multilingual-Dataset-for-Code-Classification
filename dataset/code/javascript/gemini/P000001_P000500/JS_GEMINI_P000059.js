const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const s = input[0];
        let prod = 1n;
        for (let c of s) {
            if (c >= '0' && c <= '9') prod *= BigInt(parseInt(c, 10));
        }
        console.log(prod.toString());
    }
}
main();