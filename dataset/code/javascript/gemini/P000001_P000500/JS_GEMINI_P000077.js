const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 4) {
        const x1 = parseFloat(input[0]), y1 = parseFloat(input[1]), x2 = parseFloat(input[2]), y2 = parseFloat(input[3]);
        const dist = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
        console.log(dist);
    }
}
main();