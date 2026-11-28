const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const r = parseFloat(input[0]);
        console.log(2 * 3.14159 * r);
    }
}
main();