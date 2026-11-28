const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const d = parseInt(input[0], 10);
        const y = Math.floor(d / 365);
        const rem = d % 365;
        const w = Math.floor(rem / 7);
        const days = rem % 7;
        console.log(`${y} Years ${w} Weeks ${days} Days`);
    }
}
main();