const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const r = parseFloat(input[0]), h = parseFloat(input[1]);
        console.log(3.14159 * r * r * h);
    }
}
main();