const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 3) {
        const p = parseFloat(input[0]);
        const r = parseFloat(input[1]);
        const t = parseFloat(input[2]);
        const a = p * Math.pow(1.0 + r / 100.0, t);
        const ci = a - p;
        console.log(ci);
    }
}
main();