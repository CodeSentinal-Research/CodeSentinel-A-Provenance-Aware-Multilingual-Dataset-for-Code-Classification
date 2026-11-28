const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const scored = parseFloat(input[0]), total = parseFloat(input[1]);
        console.log((scored / total) * 100.0);
    }
}
main();