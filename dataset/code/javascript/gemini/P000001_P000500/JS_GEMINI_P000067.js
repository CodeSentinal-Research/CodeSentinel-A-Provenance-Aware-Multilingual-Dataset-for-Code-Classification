const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1) {
        const s = parseFloat(input[0]);
        console.log(s * s);
    }
}
main();