const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const n = Math.abs(parseInt(input[0], 10));
        console.log(n.toString().length);
    }
}
main();