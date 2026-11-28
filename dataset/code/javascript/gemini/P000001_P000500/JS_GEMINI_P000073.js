const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 3) {
        const l = parseFloat(input[0]), b = parseFloat(input[1]), h = parseFloat(input[2]);
        console.log(l * b * h);
    }
}
main();